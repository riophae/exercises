/* eslint-disable no-use-before-define */

let flag = false // indicates whether the puzzle has been solved

class Pos {
  constructor(x, y) {
    this.x = x
    this.y = y
  }
}

class Element {
  constructor({ pattern }) {
    this.pattern = pattern
  }

  getPattern() {
    return this.pattern
  }

  toString() {
    return this.getPattern()
  }

  isPipe() {
    return false
  }

  canPipe(/* inputDir */) {
    return false
  }
}

class Pipe extends Element {
  constructor({ pattern, dirs }) {
    super({ pattern })
    this.dirs = dirs
  }

  isPipe() {
    return true
  }

  canPipe(inputDir) {
    return this.dirs.some((dir) => -dir === inputDir)
  }

  getOutputDir(inputDir) {
    return this.dirs.find((dir) => -dir !== inputDir)
  }
}

const DIR_T = 1
const DIR_R = 2
const DIR_B = -1
const DIR_L = -2

const dirMoveMap = {
  [DIR_T]: (pos) => new Pos(pos.x - 1, pos.y),
  [DIR_R]: (pos) => new Pos(pos.x, pos.y + 1),
  [DIR_B]: (pos) => new Pos(pos.x + 1, pos.y),
  [DIR_L]: (pos) => new Pos(pos.x, pos.y - 1),
}

const L1 = new Pipe({
  pattern: '╚',
  dirs: [DIR_T, DIR_R],
})

const L2 = new Pipe({
  pattern: '╔',
  dirs: [DIR_R, DIR_B],
})

const L3 = new Pipe({
  pattern: '╗',
  dirs: [DIR_L, DIR_B],
})

const L4 = new Pipe({
  pattern: '╝',
  dirs: [DIR_L, DIR_T],
})

const I1 = new Pipe({
  pattern: '═',
  dirs: [DIR_L, DIR_R],
})

const I2 = new Pipe({
  pattern: '║',
  dirs: [DIR_T, DIR_B],
})

const L_PIPES = [
  L1, L2, L3, L4,
]

const I_PIPES = [
  I1, I2,
]

const pipes = [
  ...L_PIPES,
  ...I_PIPES,
]

const Tree = new Element({
  pattern: '♣',
})

function getRotated(pipe) {
  if (L_PIPES.includes(pipe)) {
    return L_PIPES
  } else if (I_PIPES.includes(pipe)) {
    return I_PIPES
  }
  throw new Error('You should not reach here.')
}

function convertPatternToPipe(pattern) {
  return (
    pipes.find((pipe) => pipe.getPattern() === pattern) ||
    Tree
  )
}

const map = `
═╗═╗
╚═╗♣
╔╗═╚
║╚╚═
╚══╝
`
.trim()
.split('\n')
.map((row) => row.split('').map(convertPatternToPipe))

function isOutOfMap(pos) {
  return (
    pos.x < 0 ||
    pos.y < 0 ||
    pos.x >= map.length ||
    pos.y >= map[0].length
  )
}

const book = map.map((row) => row.map(() => false))

const entryPos = new Pos(0, 0)
const entryDir = DIR_R
const exitPos = new Pos(map.length - 1, map[0].length)

function isSamePos(posA, posB) {
  return (
    posA.x === posB.x &&
    posA.y === posB.y
  )
}

function printMap() {
  console.log(map.map((row) => row.join('')).join('\n'))
}

function dfs(currPos, prevDir) {
  if (flag || book[currPos.x][currPos.y]) return
  if (isSamePos(currPos, exitPos)) {
    flag = true
    printMap()
    console.log('Success!')
    return
  }
  if (isOutOfMap(currPos)) return

  const curr = map[currPos.x][currPos.y]
  if (!curr.isPipe()) return

  book[currPos.x][currPos.y] = true

  getRotated(curr).forEach((rotatedPipe) => {
    if (!rotatedPipe.canPipe(prevDir)) return
    const outputDir = rotatedPipe.getOutputDir(prevDir)
    const nextPos = dirMoveMap[outputDir](currPos)
    map[currPos.x][currPos.y] = rotatedPipe
    dfs(nextPos, outputDir)
  })

  book[currPos.x][currPos.y] = false
}

function main() {
  dfs(entryPos, entryDir)
}

main()
