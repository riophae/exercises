function findLongestPalindromes(str) {
  str = `#${str.split('').join('#')}#`
  const p = Array(str.length).fill(0)

  for (let i = 0; i < str.length; i++) {
    p[i] = 1

    while (i - p[i] >= 0 && i + p[i] < str.length && str[i - p[i]] === str[i + p[i]]) {
      ++p[i]
    }

    let j = 0
    while (i - ++j > 0) {
      if (p[i - j] - 1 > j && p[i - j] >= p[i]) {
        p[i] = 1
        break
      }
      if (p[i] - 1 > j && p[i] >= p[i - j]) {
        p[i - j] = 1
      }
    }
  }

  const palindromes = []
  for (let i = 1; i < str.length; i++) {
    if (p[i] > 1) {
      let palindrome = ''
      for (let j = i - (p[i] - 1) + 1; j <= i + (p[i] - 1) - 1; j += 2) {
        palindrome += str[j]
      }
      palindromes.push(palindrome)
    }
  }
  console.log(palindromes.join(' '))
}

function main() {
  const strings = [
    'habbafgh',
    'abcdef',
    'aaaa',
    '',
    'x',
  ]
  for (const string of strings) {
    findLongestPalindromes(string)
  }
}

main()
