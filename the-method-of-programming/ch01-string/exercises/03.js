function countOccurrences(str) {
  const count = {}
  for (let i = 0; i < str.length; ++i) {
    const char = str[i]
    count[char] = (count[char] || 0) + 1
  }
  console.log(count)
}

function main() {
  countOccurrences('*Riophae*Lee*')
}

main()
