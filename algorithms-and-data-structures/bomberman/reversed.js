const data = require('./data')
const {
  isWall,
  isEnemy,
  isBlank,
  positionGenerators,
  printResult,
} = require('./util')

function main() {
  const result = data.map(() => [])

  for (let x = 0; x < data.length; x++) {
    for (let y = 0; y < data[x].length; y++) {
      const pos = [x, y]
      if (isEnemy(pos)) {
        positionGenerators.forEach((gen) => {
          let bPos = pos.slice()
          while (!isWall(bPos = gen(bPos))) {
            if (isBlank(bPos)) {
              const [bX, bY] = bPos
              result[bX][bY] = (result[bX][bY] || 0) + 1
            }
          }
        })
      }
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

  return {
    polePos,
    poleValue,
  }
}

module.exports = main

if (module === require.main) {
  printResult(main())
}
