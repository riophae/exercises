/* eslint-disable class-methods-use-this */

const _ = ' '
const X = 'X'
const O = 'O'

const SIZE = 3
const BEGIN = -1
const END = 1

function from(x) {
  return {
    to(y) {
      const arr = []
      for (let i = x; i <= y; i++) {
        arr.push(i)
      }
      return arr
    },
  }
}

class Chessboard {
  constructor() {
    this._data = this._initChessboard()
    this._currentType = O
  }

  _iterate(func) {
    for (let i = BEGIN; i <= END; i++) {
      func(i)
    }
  }

  _get(indexes) {
    return indexes.map(([x, y]) => this._data[x][y])
  }

  _getRowItems(x) {
    const items = []
    this._iterate((y) => {
      items.push(this._data[x][y])
    })
    return items
  }

  _getColumnItems(y) {
    const items = []
    this._iterate((x) => {
      items.push(this._data[x][y])
    })
    return items
  }

  _initChessboard() {
    const data = []
    this._iterate((x) => {
      data[x] = []
      this._iterate((y) => {
        data[x][y] = _
      })
    })
    return data
  }

  _switchType() {
    this._currentType = this._currentType === O ? X : O
  }

  __checkPos(n) {
    const temp = parseInt(n, 0)
    return (
      temp === n &&
      n >= BEGIN &&
      n <= END
    )
  }

  _checkPos(x, y) {
    return (
      this.__checkPos(x) &&
      this.__checkPos(y)
    )
  }

  _isBlank(x, y) {
    return this._data[x][y] === _
  }

  set(x, y) {
    if (!this._checkPos(x, y)) {
      throw new Error(`Illegal position (${x}, ${y})!`)
    }

    if (!this._isBlank(x, y)) {
      throw new Error(`Can not put chess piece at (${x}, ${y}) since it's not blank there!`)
    }

    this._data[x][y] = this._currentType
    this._switchType()

    if (this._isEnded()) {
      this._end()
    }
  }

  print() {
    const sep = Array(SIZE).fill('-').join('-')

    this._iterate((x) => {
      console.log(this._getRowItems(x).join('|'))
      if (x !== END) console.log(sep)
    })

    console.log()
  }

  _isEnded() {
    const metaIndexes = from(BEGIN).to(END)
    const horizontalIndexes = metaIndexes.map(x => metaIndexes.map(y => [x, y]))
    const verticalIndexes = metaIndexes.map(x => metaIndexes.map(y => [y, x]))
    const tiltedIndexes = [
      metaIndexes.map(i => [i, i]),
      metaIndexes.map(i => [i, -i]),
    ]
    const arrayOfIndexes = [
      ...horizontalIndexes,
      ...verticalIndexes,
      ...tiltedIndexes,
    ]

    return arrayOfIndexes.some((indexes) => {
      const set = new Set(this._get(indexes))
      return set.size === 1 && !set.has(_)
    })
  }

  _end() {
    this._ended = true
    console.log('Game end')
  }
}

const board = new Chessboard()
board.set(0, 0)
board.print()
board.set(0, 1)
board.print()
board.set(-1, 0)
board.print()
board.set(-1, 1)
board.print()
board.set(1, 0)
board.print()
