// https://en.wikipedia.org/wiki/Heap_(data_structure)

const utils = {
  getParentIndex(childIdx) {
    return Math.ceil(childIdx / 2) - 1
  },

  getChildrenIndex(parentIdx) {
    const childIdx2 = 2 * (parentIdx + 1)
    const childIdx1 = childIdx2 - 1
    return [childIdx1, childIdx2]
  },

  swap(obj, keyA, keyB) {
    [obj[keyA], obj[keyB]] = [obj[keyB], obj[keyA]]
  },

  isLessThan(a, b) {
    return a < b
  },

  isGreaterThan(a, b) {
    return a > b
  },
}

class Heap {
  constructor(comparer, data = []) {
    this._data = data
    this._swap = utils.swap.bind(null, this._data)
    this._comparer = comparer
  }

  size() {
    return this._data.length
  }

  isEmpty() {
    return this.size() === 0
  }

  insert(elem) {
    this._data.push(elem)
    this._siftUp()
  }

  replace(elem) {
    this._data[0] = elem
    this._siftDown()
  }

  _peek() {
    return this._data[0]
  }

  _removeRootNode() {
    this._data.shift()

    if (this.size() > 1) {
      this._data.unshift(this._data.pop())
      this._siftDown()
    }
  }

  _extractRootNode() {
    const head = this._data[0]
    this._removeRootNode()
    return head
  }

  _checkEmpty(errMsg) {
    if (!this.size()) {
      throw new Error(`Unable to ${errMsg}: the heap is empty.`)
    }
  }

  _siftUp() {
    if (this.size() < 2) {
      return
    }

    let lightIdx = this.size() - 1
    let parentIdx = utils.getParentIndex(lightIdx)

    while (parentIdx > -1 && this._comparer(this._data[lightIdx], this._data[parentIdx])) {
      this._swap(lightIdx, parentIdx)
      lightIdx = parentIdx
      parentIdx = utils.getParentIndex(parentIdx)
    }
  }

  _siftDown() {
    if (this.size() < 2) {
      return
    }

    let heavyIdx = 0
    let [childIdx1, childIdx2] = utils.getChildrenIndex(heavyIdx)
    let lightIdx
    const idxLimit = this.size() - 1

    while (true) {
      if (childIdx1 > idxLimit) {
        break
      } else if (childIdx2 > idxLimit) {
        lightIdx = childIdx1
      } else {
        lightIdx = this._comparer(this._data[childIdx1], this._data[childIdx2])
          ? childIdx1
          : childIdx2
      }

      if (this._comparer(this._data[lightIdx], this._data[heavyIdx])) {
        this._swap(lightIdx, heavyIdx)
        heavyIdx = lightIdx
        ;[childIdx1, childIdx2] = utils.getChildrenIndex(heavyIdx)
      } else {
        break
      }
    }
  }
}

class MinHeap extends Heap {
  constructor(data) {
    super(utils.isLessThan, data)
  }

  static createHeap() {
    return new MinHeap()
  }

  static heapify(arr) {
    const heap = new MinHeap()
    arr.forEach(heap.insert.bind(heap))
    return heap
  }

  findMin() {
    this._checkEmpty('find min')
    return this._peek()
  }

  deleteMin() {
    this._checkEmpty('delete min')
    return this._deleteRootNode()
  }

  extractMin() {
    this._checkEmpty('extract min')
    return this._extractRootNode()
  }

  merge(anotherHeap) {
    if (!(anotherHeap instanceof MinHeap)) {
      throw new Error('The heap provided should be of MinHeap.')
    }

    const heap = new MinHeap(this._data.slice())
    anotherHeap._data.forEach(heap.insert.bind(heap))
    return heap
  }

  meld(anotherHeap) {
    if (!(anotherHeap instanceof MinHeap)) {
      throw new Error('The heap provided should be of MinHeap.')
    }

    anotherHeap._data.forEach(this.insert.bind(this))
    return this
  }
}

class MaxHeap extends Heap {
  constructor(data) {
    super(utils.isGreaterThan, data)
  }

  static createHeap() {
    return new MaxHeap()
  }

  static heapify(arr) {
    const heap = new MaxHeap()
    arr.forEach(heap.insert.bind(heap))
    return heap
  }

  findMax() {
    this._checkEmpty('find max')
    return this._peek()
  }

  deleteMax() {
    this._checkEmpty('delete max')
    return this._deleteRootNode()
  }

  extractMax() {
    this._checkEmpty('extract max')
    return this._extractRootNode()
  }

  merge(anotherHeap) {
    if (!(anotherHeap instanceof MaxHeap)) {
      throw new Error('The heap provided should be of MaxHeap.')
    }

    const heap = new MaxHeap(this._data.slice())
    anotherHeap._data.forEach(heap.insert.bind(heap))
    return heap
  }

  meld(anotherHeap) {
    if (!(anotherHeap instanceof MaxHeap)) {
      throw new Error('The heap provided should be of MaxHeap.')
    }

    anotherHeap._data.forEach(this.insert.bind(this))
    return this
  }
}

module.exports = {
  utils,
  MinHeap,
  MaxHeap,
}
