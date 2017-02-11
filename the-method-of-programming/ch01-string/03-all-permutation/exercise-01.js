'use strict'

function convertBase(num, base, len) {
  const digits = []

  while (num > 0) {
    const r = num % base
    digits.unshift(r)
    num = (num - r) / base
  }

  while (digits.length < len) {
    digits.unshift(0)
  }

  return digits
}

function calcAllPermutations(str) {
  const base = str.length
  const max = base ** base
  let i = 0

  while (i < max) {
    const digits = convertBase(i, base, base)
    const permutation = digits.map(d => str[d]).join('')
    console.log(permutation)
    i++
  }
}

function main() {
  calcAllPermutations('abc')
}

main()
