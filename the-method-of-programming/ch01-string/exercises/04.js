'use strict'

const assert = require('assert')

const match = (function () {
  function _match(text, pattern) {
    let finding = null
    let matchStartAt = -1

    for (let startAt = 0; startAt <= text.length; startAt++) {
      let matched = ''
      let noMismatch = true

      for (let index = 0, offset = 0; index < pattern.length; index++, offset++) {
        const charPos = startAt + offset
        const toMatch = pattern[index]

        if (toMatch === '*') {
          const restText = text.substr(charPos)
          const restPattern = pattern.substr(index + 1)

          if (restPattern === '') {
            matched += restText
          } else {
            const result = _match(restText, restPattern)

            if (result.finding !== null) {
              matched += restText.substring(0, result.matchStartAt)
              matched += result.finding
              break
            } else {
              noMismatch = false
              break
            }
          }
        } else {
          if (charPos >= text.length) {
            noMismatch = false
            break
          }

          const char = text[charPos]

          if (toMatch === '?') {
            matched += char
          } else if (toMatch === char) {
            matched += char
          } else {
            noMismatch = false
            break
          }
        }
      }

      if (noMismatch) {
        finding = matched
        matchStartAt = startAt
        break
      }
    }

    return {
      finding,
      matchStartAt,
    }
  }

  return function (text, pattern) {
    return _match(text, pattern).finding
  }
}())

function main() {
  const data = [{
    text: 'hello world',
    pattern: '?d',
    expected: 'ld',
  }, {
    text: 'hello world',
    pattern: 'x',
    expected: null,
  }, {
    text: 'hello world',
    pattern: 'worxld',
    expected: null,
  }, {
    text: 'hello world',
    pattern: 'ld?',
    expected: null,
  }, {
    text: 'abc',
    pattern: '?',
    expected: 'a',
  }, {
    text: 'John Smith',
    pattern: 'J* Smi??',
    expected: 'John Smith',
  }, {
    text: 'abc',
    pattern: 'abc*',
    expected: 'abc',
  }, {
    text: 'Riophae Lee',
    pattern: '*',
    expected: 'Riophae Lee',
  }, {
    text: 'abc',
    pattern: '**',
    expected: 'abc',
  }, {
    text: 'abc',
    pattern: '**??**??**',
    expected: null,
  }]

  data.forEach(({ text, pattern, expected }) => {
    const found = match(text, pattern)
    assert.strictEqual(found, expected)
  })
}

main()
