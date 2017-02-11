function _calcAllPermutations(prefix, level, from) {
  for (let i = from; i <= 26 - level; i++) {
    const str = prefix + String.fromCharCode(97 + i)
    if (level > 1) _calcAllPermutations(str, level - 1, i + 1)
    else console.log(str)
  }
}

function calcAllPermutations(n) {
  _calcAllPermutations('', n, 0)
}

function main() {
  calcAllPermutations(3)
}

main()
