const _ = require('lodash')

class LinkedList {
  constructor() {
    this.exponent = 0
    this.coefficient = 0
    this.next = null
  }

  static first(list) {
    return list.next
  }

  static findLast(list) {
    return list.next === null
      ? list
      : LinkedList.findLast(list.next)
  }

  static isLast(list) {
    return list.next === null
  }
}

function createPolynomialLinkedListFromArray(argList) {
  return argList.reduceRight((next, [exponent, coefficient]) => {
    const curr = new LinkedList()
    curr.exponent = exponent
    curr.coefficient = coefficient
    curr.next = next
    return curr
  }, null)
}

function polynomialMultiply(polynomialA, polynomialB, countA, countB) {
  const count = countA * countB
  const resultArr = Array(count)

  let pointerA = polynomialA
  let pointerB
  let i = 0

  while (pointerA) {
    pointerB = polynomialB

    while (pointerB) {
      resultArr[i] = {
        exponent: pointerA.exponent + pointerB.exponent,
        coefficient: pointerA.coefficient * pointerB.coefficient,
      }

      pointerB = pointerB.next
      i++
    }

    pointerA = pointerA.next
  }

  const sortedResultArr = _.sortBy(resultArr, 'exponent')
  const resultLinkedList = new LinkedList()
  let pointer = resultLinkedList

  sortedResultArr.forEach((curr, index) => {
    let prev
    if (index === 0 || (prev = sortedResultArr[index - 1], curr.exponent !== prev.exponent)) {
      pointer = pointer.next = new LinkedList()
      pointer.exponent = curr.exponent
      pointer.coefficient = curr.coefficient
    } else {
      pointer.coefficient += curr.coefficient
    }
  })

  return LinkedList.first(resultLinkedList)
}

function main() {
  const polynomialA = createPolynomialLinkedListFromArray([[0, 1], [2, 3], [10, 2]])
  const polynomialB = createPolynomialLinkedListFromArray([[0, 2], [1, 4], [2, 3], [4, 3]])
  const result = polynomialMultiply(polynomialA, polynomialB, 3, 4)
  let pointer = result
  let output = ''
  while (pointer) {
    if (pointer.coefficient > 0) output += pointer.coefficient
    if (pointer.exponent > 0) output += 'x'
    if (pointer.exponent > 1) output += `^${pointer.exponent}`
    if (!LinkedList.isLast(pointer)) output += ' + '
    pointer = pointer.next
  }
  console.log(output)
}

main()
