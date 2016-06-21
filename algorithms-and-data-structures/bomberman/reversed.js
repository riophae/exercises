const data = require('./data')
const {
  isWall,
  isEnemy,
  isBlank,
  positionGenerators,
  printResult,
} = require('./util')

function main() {
  const result = data.map((row) => row.map(() => 0))

  for (let x = 0; x < data.length; x++) {
    for (let y = 0; y < data[x].length; y++) {
      const pos = [x, y]
      if (!isEnemy(pos)) continue
      positionGenerators.forEach((gen) => {
        let bPos = pos.slice()
        while (!isWall(bPos = gen(bPos))) {
          if (isBlank(bPos)) {
            const [bX, bY] = bPos
            result[bX][bY]++
          }
        }
      })
    }
  }

  let poleValue = 0
  let polePos
  result.forEach((row, x) => {
    row.forEach((val, y) => {
      if (val > poleValue) {
        poleValue = val
        polePos = [x, y]
      }
    })
  })

  printResult(polePos, poleValue)
}

main()
