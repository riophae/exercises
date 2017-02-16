'use strict'

const assert = require('assert')

class LinkedList {
  constructor(value, next = null) {
    this.value = value
    this.next = next
  }

  static createFromArray(arr) {
    return arr.slice(0, -1).reduceRight(
      (next, elem) => new LinkedList(elem, next),
      new LinkedList(arr[arr.length - 1]),
    )
  }

  toArray() {
    const arr = []
    let node = this

    do {
      arr.push(node.value)
      node = node.next
    } while (node !== null)

    return arr
  }
}

function calcComplementSet(setA, setB) {
  const head = new LinkedList(null, setA)
  let b = setB

  while (b !== null) {
    let prev = head
    let a = setA

    while (a !== null) {
      if (a.value === b.value) {
        prev.next = a.next
        break
      } else {
        prev = a
      }
      a = a.next
    }

    b = b.next
  }

  return head.next
}

function main() {
  const setA = LinkedList.createFromArray([5, 10, 20, 15, 25, 30])
  const setB = LinkedList.createFromArray([5, 15, 35, 25])
  const result = calcComplementSet(setA, setB)
  const expected = LinkedList.createFromArray([10, 20, 30])
  assert.deepStrictEqual(result, expected)
}

main()
