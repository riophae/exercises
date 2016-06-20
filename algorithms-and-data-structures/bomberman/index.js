const _ = require('lodash')
const data = require('./data')

const indexGenerators = [
  ([x, y]) => [x + 1, y],
  ([x, y]) => [x - 1, y],
  ([x, y]) => [x, y + 1],
  ([x, y]) => [x, y - 1],
]

function isWall([x, y]) {
  return data[x][y] === '#'
}

function isEnemy([x, y]) {
  return data[x][y] === 'G'
}

function isBlank([x, y]) {
  return data[x][y] === '.'
}

function sumEnemies([x, y]) {
  return _.sum(indexGenerators.map((gen) => {
    let i = 0
    let pos = gen([x, y])
    while (!isWall(pos)) {
      if (isEnemy(pos)) i++
      pos = gen(pos)
    }
    return i
  }))
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

  console.log(`Pole value is ${poleValue} at (${polePos[0]}, ${polePos[1]})`)
}

main()
