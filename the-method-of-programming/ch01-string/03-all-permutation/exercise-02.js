function calcAllCombinations(str) {
  const base = str.length
  const max = base * 2 + 1
  let n = 1

  while (n <= max) {
    let i = 0
    let perm = ''
    while (i < base) {
      if ((1 << i) & n) perm += str[i]
      i++
    }
    console.log(perm)
    n++
  }
}

function main() {
  calcAllCombinations('abc')
}

main()
