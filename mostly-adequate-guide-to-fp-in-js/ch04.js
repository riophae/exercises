const { test } = require('tap')
const { curry } = require('lodash')

test('exercise-1', (t) => {
  const split = curry((what, str) => str.split(what))
  const words = split(' ')

  const value = words('hello world')
  const expected = ['hello', 'world']
  t.deepEqual(value, expected)
  t.end()
})

test('exercise-1a', (t) => {
  const map = curry((fn, arr) => arr.map(fn))
  const split = curry((what, str) => str.split(what))
  const words = split(' ')
  const sentences = map(words)

  const value = sentences([
    'fp is awesome',
    'you are gonna love it',
  ])
  const expected = [
    ['fp', 'is', 'awesome'],
    ['you', 'are', 'gonna', 'love', 'it'],
  ]
  t.deepEqual(value, expected)
  t.end()
})

test('exercise-2', (t) => {
  const filter = curry((fn, arr) => arr.filter(fn))
  const match = curry((what, str) => str.match(what))
  const matchQ = match(/q/i)
  const filterQs = filter(matchQ)

  const value = filterQs(['a', 'b', 'q', 'x'])
  const expected = ['q']
  t.deepEqual(value, expected)
  t.end()
})

test('exercise-3', (t) => {
  const reduce = curry((fn, initVal, arr) => arr.reduce(fn, initVal))
  const _keepHighest = (x, y) => (x >= y ? x : y) // `Math.max` works too
  const max = reduce(_keepHighest, -Infinity)

  const xs = [2, 7, 3, 5]
  const value = max(xs)
  const expected = 7
  t.equal(value, expected)
  t.end()
})

test('bonus-1', (t) => {
  const slice = from => to => arr => arr.slice(from, to)

  const value = slice(0)(2)([1, 2, 3])
  const expected = [1, 2]
  t.deepEqual(value, expected)
  t.end()
})

test('bonus-2', (t) => {
  const slice = from => to => arr => arr.slice(from, to)
  const take = slice(0)

  const value = take(1)(['a', 'b', 'c'])
  const expected = ['a']
  t.deepEqual(value, expected)
  t.end()
})
