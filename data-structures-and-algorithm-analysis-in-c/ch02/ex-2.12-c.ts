'use strict'

const assert = require('assert')

function _maxSubSequenceProduct(values: ReadonlyArray<number>): number {
  if (values.length === 1) return values[0]

  let product = 1
  let firstNegativeProduct = 0
  let lastNegativeProduct = 0
  let i

  for (i = 0; i < values.length; i++) {
    const value = values[i]

    product *= value

    if (lastNegativeProduct !== 0) {
      lastNegativeProduct *= value
    }

    if (value < 0) {
      if (firstNegativeProduct === 0) {
        firstNegativeProduct = product
      }
      lastNegativeProduct = value
    }
  }

  if (product < 0 && values.length > 1 && lastNegativeProduct !== 0) {
    product /= Math.max(firstNegativeProduct, lastNegativeProduct)
  }

  return product
}

function maxSubSequenceProduct(values: ReadonlyArray<number>): number {
  let i = 0
  let start = -1
  let end
  const products = [0]

  while (i < values.length && values[i] === 0) i++
  start = i

  while (i < values.length) {
    while (i < values.length && values[i] !== 0) end = ++i
    products.push(_maxSubSequenceProduct(values.slice(start, end)))
    while (i + 1 < values.length && values[i + 1] === 0) i++
    start = ++i
  }

  return Math.max(...products)
}

function main() {
  const testData = [{
    values: [5, 2, -3, 7, 0, 4, 9, -2, 8, -1, 2],
    expected: 1152,
  }, {
    values: [2, -2, -5, -8, 1, -3, -3],
    expected: 480,
  }, {
    values: [1, 2, -3, 4, 5],
    expected: 20,
  }, {
    values: [-1, 0, -1],
    expected: 0,
  }, {
    values: [5, 2, 7, 1, -2, 0, 0, -1, 4, 9, 1, 2],
    expected: 72,
  }, {
    values: [1, -1],
    expected: 1,
  }, {
    values: [0, -1],
    expected: 0,
  }, {
    values: [-1],
    expected: 0,
  }, {
    values: [],
    expected: 0,
  }]

  testData.forEach(({ values, expected }) => {
    assert.strictEqual(maxSubSequenceProduct(values), expected)
  })
}

main()
