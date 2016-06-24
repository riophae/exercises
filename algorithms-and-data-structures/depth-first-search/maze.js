const _ = require('lodash')

const maze = [
  [0, 0, 1, 0],
  [0, 0, 0, 0],
  [0, 0, 1, 0],
  [0, 1, 0, 0],
  [0, 0, 0, 1],
]
const entry = [0, 0]
const goal = [3, 2]
const positionGenerators = [
  ([x, y]) => [x, y + 1],
  ([x, y]) => [x + 1, y],
  ([x, y]) => [x, y - 1],
  ([x, y]) => [x - 1, y],
]
const steps = []
const paths = []

function isEqual(posA, posB) {
  return (
    posA[0] === posB[0] &&
    posA[1] === posB[1]
  )
}

function serialize(pos) {
  const [x, y] = pos
  return `(${x}, ${y})`
}

function dfs(currPos, step) {
  if (isEqual(currPos, goal)) {
    const path = steps.filter(Boolean)
    paths.push(path)
    return
  }

  positionGenerators.forEach((gen) => {
    const nextPos = gen(currPos)
    const [x, y] = nextPos
    if (!(Array.isArray(maze[x]) && maze[x][y] === 0)) return
    const serialized = serialize(nextPos)
    if (!steps.includes(serialized)) {
      steps[step] = serialized
      dfs(nextPos, step + 1)
      steps[step] = undefined
    }
  })
}

function main() {
  dfs(entry, 0)
  const shortestPath = _.minBy(paths, (path) => path.length)
  console.log(shortestPath.join(' '))
}

main()
