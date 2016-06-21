const assert = require('assert')

const basic = require('./basic')
const reversed = require('./reversed')

const expected = {
  polePos: [9, 9],
  poleValue: 8,
}

assert.deepEqual(basic(), expected)
assert.deepEqual(reversed(), expected)
