const assert = require('assert')

const DATA = [4, 2, 5, 3, 5, 5, 1, 1, 1, 3, 3]

const alwaysTrue = () => true
const alwaysFalse = () => false
const pickCurr = (acceptFn) => ({ curr }) => acceptFn(curr)

function get(idxGenerator) {
  let i
  let curr
  let prev
  const accepted = []

  while ((i = idxGenerator.next({ curr, prev, accepted })) && !i.done) {
    const {
      index = alwaysFalse,
      done = alwaysFalse,
      flush = alwaysFalse,
      accept = alwaysTrue,
    } = i.value

    prev = curr
    curr = DATA[index]

    if (done({ curr, prev, accepted })) {
      if (!i.done) idxGenerator.return()
      break
    }

    if (flush({ curr, prev, accepted })) {
      accepted.length = 0
    }

    if (accept({ curr, prev, accepted })) {
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

const acceptLessThanThree = (n) => n < 3
const lessThanThree = get(function *() {
  let i = 0

  while (i < DATA.length) {
    const { curr } = yield { index: i, accept: pickCurr(acceptLessThanThree) }
    assert.equal(curr, DATA[i])
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

const specificedIndexes = [3, 0]
const specificed = get(function *() {
  yield* specificedIndexes.map((index) => ({ index }))
}())
assert.deepEqual(specificed, specificedIndexes.map((idx) => DATA[idx]))

const firstTheThreeSameInterfacingOnes = get(function *() {
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
assert.deepEqual(firstTheThreeSameInterfacingOnes, [1, 1, 1])
