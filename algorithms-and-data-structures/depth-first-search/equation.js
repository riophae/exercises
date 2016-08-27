const _ = require('lodash')

const numbers = []
const book = []

function convertNumber([x, y, z]) {
  return (
    (x * 100) +
    (y * 10) +
    z
  )
}

function dfs(step) {
  if (step === 9) {
    const [a, b, c] = _.chunk(numbers, 3).map(convertNumber)
    if (a + b === c) {
      console.log(`${a} + ${b} = ${c}`)
    }
    return
  }

  for (let i = 1; i <= 9; i++) {
    if (!book[i]) {
      book[i] = true
      numbers[step] = i
      dfs(step + 1)
      book[i] = false
    }
  }
}

function main() {
  dfs(0)
}

main()
