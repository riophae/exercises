/* eslint-disable */

const { test } = require('tap')
const equal = require('./lib')

test('equal', function (t) {
  t.ok(equal({
    a: [2, 3],
    b: [4],
  }, {
    a: [2, 3],
    b: [4],
  }))
  t.ok(equal([3, 4, 5], [3, 4, 5]))
  t.end()
})

test('not equal', function (t) {
  t.notOk(equal({
    x: 5,
    y: [6],
  }, {
    x: 5,
    y: 6,
  }))
  t.notOk(equal({
    a: 1,
    b: 2,
  }, {
    a: 3,
    c: 4,
  }))
  t.notOk(equal([3, 4], [3, 4, 5]))
  t.end()
})

test('nested nulls', function (t) {
  t.ok(equal([null, null, null], [null, null, null]))
  t.ok(equal([null, undefined, null], [undefined, null, undefined]))
  t.end()
})

test('non-objects', function (t) {
  t.ok(equal(3, 3))
  t.ok(equal('beep', 'beep'))
  t.notOk(equal('3', 3))
  t.notOk(equal('3', [3]))
  t.ok(equal(NaN, NaN))
  t.ok(equal(true, new Boolean(true)))
  t.end()
})

test('arguments class', function (t) {
  t.ok(equal(
        (function () {
          return arguments
        })(1, 2, 3), (function () {
          return arguments
        })(1, 2, 3),
        'compares arguments'
    ))
  t.notOk(equal(
        (function () {
          return arguments
        })(1, 2, 3), [1, 2, 3],
        'differenciates array and arguments'
    ))
  t.end()
})

test('functions', function (t) {
  const fn0 = function () {}
  const fn1 = function () {}
  t.ok(equal(fn0, fn0))
  t.notOk(equal(fn0, fn1))
  t.notOk(equal(fn0, '2'))
  t.end()
})

test('dates', function (t) {
  const d0 = new Date(1387585278000)
  const d1 = new Date('Fri Dec 20 2013 16:21:18 GMT-0800 (PST)')
  t.ok(equal(d0, d1))
  t.end()
})

test('regexps', function (t) {
  const re0 = /aBc/i
  const re1 = /aBc/g
  const re2 = /aBc/i
  t.notOk(equal(re0, re1))
  t.ok(equal(re0, re2))
  t.end()
})

test('buffers', function (t) {
  t.ok(equal(Buffer('xyz'), Buffer('xyz')))
  t.notOk(equal(Buffer('abc'), Buffer('edf')))
  t.end()
})

test('booleans and arrays', function (t) {
  t.notOk(equal(true, []))
  t.end()
})
