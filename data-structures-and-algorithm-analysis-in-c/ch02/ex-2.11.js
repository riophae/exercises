const assert = require('assert')
const _ = require('lodash')

function search(arr) {
  let low = 0
  let high = arr.length - 1
  let mid

  while (low <= high) {
    mid = Math.floor((low + high) / 2)

    if (arr[mid] === mid) {
      return mid
    } else if (arr[mid] > mid) {
      high = mid - 1
    } else if (arr[mid] < mid) {
      low = mid + 1
    }
  }

  return -1
}

function validate(arr, expected) {
  return _.isEqual(arr.filter((n, i) => n === i), expected)
}

function padSpaces(number) {
  return _.padStart(number, 3, ' ')
}

function random(lower, upper) {
  return Math.random() * (upper - lower) + lower
}

function randomInteger(lower, upper) {
  return Math.floor(random(lower, upper))
}

function sort(arr) {
  return arr.sort((a, b) => a - b)
}

function appendElement(arr, generator) {
  let element
  while (((element = generator()), arr.includes(element)));
  arr.push(element)
}

function test() {
  const head = []
  const tail = []
  const count = 999
  const flag = Math.random() < 0.5
  let equalAt = -1

  if (flag) {
    equalAt = randomInteger(0, count)
  }

  for (let i = 0; i < count; i++) {
    if (flag) {
      if (i < equalAt) {
        appendElement(head, () => randomInteger(-count, i))
      } else if (i > equalAt) {
        appendElement(tail, () => randomInteger(i, count * 2))
      }
    } else {
      appendElement(head, () => randomInteger(-count, count))
    }
  }
  sort(head)
  sort(tail)

  const arr = flag
    ? head.concat(equalAt).concat(tail)
    : head.concat(tail)

  if (!validate(arr, flag ? [] : [equalAt])) {
    return test()
  }

  const index = search(arr)
  return [equalAt, index, arr[index]]
}

function main() {
  let i = 0

  while (++i <= 100) {
    const [equalAt, index, value] = test()
    const output = [
      `[${padSpaces(i)}]`,
      `equalAt: ${padSpaces(equalAt)}`,
      `index: ${padSpaces(index)}`,
    ]
    if (equalAt === -1) {
      assert(index === -1)
    } else {
      output.push(`value: ${padSpaces(value)}`)
      assert(equalAt === index && index === value)
    }
    console.log(output.join(' '))
  }
}

main()
