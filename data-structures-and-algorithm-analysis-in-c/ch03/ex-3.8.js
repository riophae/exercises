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

function polynomialPow(rawPolynomialData, exp) {
  const circularLinkedListOfPolynomial = rawPolynomialData.reduceRight((next, [exponent, coefficient]) => {
    const curr = new LinkedList()
    curr.exponent = exponent
    curr.coefficient = coefficient
    curr.next = next
    return curr
  }, null)
  const headOfCircularList = circularLinkedListOfPolynomial
  LinkedList.findLast(circularLinkedListOfPolynomial).next = headOfCircularList

  let i = 0
  const count = rawPolynomialData.length ** exp
  const permutationArr = Array(exp).fill(headOfCircularList)
  const resultArr = Array(count)

  while (i < count) {
    resultArr[i] = {
      exponent: _.sumBy(permutationArr, item => item.exponent),
      coefficient: _(permutationArr).map(item => item.coefficient).reduce(_.multiply),
    }

    for (let j = 0; j < permutationArr.length; j++) {
      permutationArr[j] = permutationArr[j].next
      if (permutationArr[j] !== headOfCircularList) break
    }

    i++
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
  const data = [[1, 2], [3, 9], [4, 10]]
  const exp = 3
  const result = polynomialPow(data, exp)
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
