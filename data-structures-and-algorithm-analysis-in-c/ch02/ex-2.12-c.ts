'use strict'

const assert = require('assert')

function maxSubSequenceProduct(values: ReadonlyArray<number>): number {
  if (values.length === 0) return 0
  if (values.length === 1) return Math.max(values[0], 0)

  let product = 1
  let maxProductOfRest = 0
  let firstNegativeProduct = 0
  let lastNegativeProduct = 0
  let i

  for (i = 0; i < values.length; i++) {
    const value = values[i]

    if (value === 0) {
      product = i === 0 ? 0 : product;
      maxProductOfRest = maxSubSequenceProduct(values.slice(i + 1))
      break
    } else {
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
  }

  if (product < 0) {
    if (i > 1 && lastNegativeProduct !== 0) {
      product /= Math.max(firstNegativeProduct, lastNegativeProduct)
    } else {
      product = 0
    }
  }

  return Math.max(product, maxProductOfRest)
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
    values: [5, 2, 7, 1, -2, 0, -1, 4, 9, 1, 2],
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
