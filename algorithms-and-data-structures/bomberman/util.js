const data = require('./data')

function isWall([x, y]) {
  return data[x][y] === '#'
}

function isEnemy([x, y]) {
  return data[x][y] === 'G'
}

function isBlank([x, y]) {
  return data[x][y] === '.'
}

const positionGenerators = [
  ([x, y]) => [x + 1, y],
  ([x, y]) => [x - 1, y],
  ([x, y]) => [x, y + 1],
  ([x, y]) => [x, y - 1],
]

function printResult({ polePos, poleValue }) {
  const [x, y] = polePos
  console.log(`Pole value is ${poleValue} at (${x}, ${y})`)
}

module.exports = {
  isWall,
  isEnemy,
  isBlank,
  positionGenerators,
  printResult,
}
