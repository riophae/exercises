const assert = require('assert')

const DATA = [4, 2, 5, 3, 5, 5, 1, 1, 1, 3, 3]

const alwaysTrue = () => true
const alwaysFalse = () => false
const pickCurr = (acceptFn) => ({ curr }) => acceptFn(curr)

function get(idxGenerator) {
  let i
  let curr
  let prev
  let args
  const accepted = []

  while ((i = idxGenerator.next({ curr, prev, accepted })) && !i.done) {
    const {
      index,
      done = alwaysFalse,
      flush = alwaysFalse,
      accept = alwaysTrue,
    } = i.value

    if (typeof index !== 'number') {
      throw new Error('Invalid argument: `index` is not provided or not a number')
    }

    prev = curr
    curr = DATA[index]
    args = { curr, prev, accepted }

    if (done(args)) {
      if (!i.done) idxGenerator.return()
      break
    }

    if (flush(args)) {
      accepted.length = 0
    }

    if (accept(args)) {
      accepted.push(curr)
    }
  }

  return accepted
}

const all = get(function *() {
  let i = 0

  while (i < DATA.length) {
    const { prev, curr, accepted } = yield { index: i }
    assert.equal(curr, DATA[i])
    if (i > 0) assert.equal(prev, DATA[i - 1])
    assert.deepEqual(accepted, DATA.slice(0, i + 1))
    i++
  }
}())
assert.deepEqual(all, DATA)

const specifiedIndexes = [3, 0]
const specified = get(function *() {
  yield* specifiedIndexes.map((index) => ({ index }))
}())
assert.deepEqual(specified, specifiedIndexes.map((idx) => DATA[idx]))

const acceptLessThanThree = (n) => n < 3
const lessThanThree = get(function *() {
  let i = 0

  while (i < DATA.length) {
    yield { index: i, accept: pickCurr(acceptLessThanThree) }
    i++
  }
}())
assert.deepEqual(lessThanThree, DATA.filter(acceptLessThanThree))

const firstTwoLessThenThree = get(function *() {
  let i = 0

  while (i < DATA.length) {
    yield {
      index: i,
      accept: ({ curr }) => curr < 3,
      done: ({ accepted }) => accepted.length === 2,
    }
    i++
  }
}())
assert.deepEqual(firstTwoLessThenThree, [2, 1])

const firstTheSameThreeInterfacingOnes = get(function *() {
  let i = 0

  while (i < DATA.length) {
    yield {
      index: i,
      accept: ({ curr, prev, accepted }) => accepted.length === 0 || curr === prev,
      flush: ({ curr, prev }) => curr !== prev,
      done: ({ accepted }) => accepted.length === 3,
    }
    i++
  }
}())
assert.deepEqual(firstTheSameThreeInterfacingOnes, [1, 1, 1])
