const n = 4
const boxes = Array(n)
const book = Array(n)

function dfs(step) {
  if (step === n) {
    console.log(boxes.join(''))
    return
  }

  for (let i = 0; i < n; i++) {
    if (!book[i]) {
      book[i] = true
      boxes[step] = i + 1
      dfs(step + 1)
      book[i] = false
    }
  }
}

function main() {
  dfs(0)
}

main()
