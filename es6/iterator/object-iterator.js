/* eslint-disable no-extend-native */

Object.prototype[Symbol.iterator] = function () {
  const obj = this
  const keys = Object.keys(obj)
  let idx = 0

  return {
    next() {
      let key
      return idx === keys.length
        ? { done: true }
        : (key = keys[idx], ++idx, { value: [obj[key], key], done: false })
    },
  }
}

const obj = { a: 1, b: 2 }

for (const [v, k] of obj) console.log(v, k)

// expected result:
//   1 "a"
//   2 "b"
