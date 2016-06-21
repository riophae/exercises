const data = require('./data')
const {
  isWall,
  isEnemy,
  isBlank,
  positionGenerators,
} = require('./util')

function sumEnemies([x, y]) {
  return positionGenerators.reduce((sum, gen) => {
    let i = 0
    let pos = gen([x, y])
    while (!isWall(pos)) {
      if (isEnemy(pos)) i++
      pos = gen(pos)
    }
    return sum + i
  }, 0)
}

function main() {
  let polePos
  let poleValue = 0

  for (let x = 0; x < data.length; x++) {
    for (let y = 0; y < data[x].length; y++) {
      const currPos = [x, y]
      if (!isBlank(currPos)) continue
      const sum = sumEnemies(currPos)
      if (poleValue < sum) {
        polePos = currPos
        poleValue = sum
      }
    }
  }

  return {
    polePos,
    poleValue,
  }
}

module.exports = main

if (module === require.main) {
  main()
}
