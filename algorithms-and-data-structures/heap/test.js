const { test } = require('tap')
const { utils, MinHeap, MaxHeap } = require('./implementation')

test('utils', (t) => {
  t.test('utils.getParentIndex()', (st) => {
    st.equal(utils.getParentIndex(1), 0)
    st.equal(utils.getParentIndex(2), 0)
    st.equal(utils.getParentIndex(3), 1)
    st.equal(utils.getParentIndex(4), 1)
    st.equal(utils.getParentIndex(5), 2)

    st.end()
  })

  t.test('utils.getChildrenIndex()', (st) => {
    st.deepEqual(utils.getChildrenIndex(0), [1, 2])
    st.deepEqual(utils.getChildrenIndex(1), [3, 4])
    st.deepEqual(utils.getChildrenIndex(2), [5, 6])

    st.end()
  })

  t.test('utils.swap()', (st) => {
    const obj = { a: 1, b: 2 }
    const expected = { a: 2, b: 1 }
    utils.swap(obj, 'a', 'b')
    st.deepEqual(obj, expected)

    st.end()
  })

  t.end()
})

test('MinHeap', (t) => {
  t.test('normal usage', (st) => {
    const heap = new MinHeap()
    st.equal(heap.isEmpty(), true)
    heap.insert(0)
    st.equal(heap.isEmpty(), false)
    st.equal(heap.size(), 1)
    heap.insert(1)
    heap.insert(2)
    st.equal(heap.findMin(), 0)
    heap.insert(3)
    heap.insert(4)
    st.deepEqual(heap._data, [0, 1, 2, 3, 4])
    st.deepEqual(heap.size(), 5)
    st.equal(heap.findMin(), 0)
    st.equal(heap.extractMin(), 0)
    st.deepEqual(heap.size(), 4)
    st.deepEqual(heap._data, [1, 3, 2, 4])
    heap.replace(5)
    st.deepEqual(heap.size(), 4)
    st.deepEqual(heap._data, [2, 3, 5, 4])
    heap.deleteMin()
    st.deepEqual(heap._data, [3, 4, 5])

    st.end()
  })

  t.test('exceptions', (st) => {
    const heap = new MinHeap()
    st.throws(
      () => heap.findMin(),
      new Error('Unable to find min: the heap is empty.')
    )
    st.throws(
      () => heap.deleteMin(),
      new Error('Unable to delete min: the heap is empty.')
    )
    st.throws(
      () => heap.extractMin(),
      new Error('Unable to extract min: the heap is empty.')
    )

    st.end()
  })

  t.test('misc', (st) => {
    const heap = MinHeap.heapify([5, 4, 3, 2, 1])
    st.equal(heap.size(), 5)
    st.equal(heap.findMin(), 1)
    st.deepEqual(heap._data, [1, 2, 4, 5, 3])

    const anotherHeap = MinHeap.heapify([7, 9, 0, 6])
    heap.meld(anotherHeap)
    st.equal(heap.size(), 9)
    st.deepEqual(heap._data, [0, 2, 1, 5, 3, 4, 6, 7, 9])

    st.end()
  })

  t.end()
})

test('MaxHeap', (t) => {
  t.test('normal usage', (st) => {
    const heap = new MaxHeap()
    heap.insert(3)
    st.equal(heap.size(), 1)
    heap.insert(5)
    st.equal(heap.size(), 2)
    st.equal(heap.findMax(), 5)
    heap.insert(0)
    st.equal(heap.size(), 3)
    st.equal(heap.findMax(), 5)
    st.deepEqual(heap._data, [5, 3, 0])
    heap.insert(3) // duplicate element
    st.equal(heap.size(), 4)
    st.deepEqual(heap._data, [5, 3, 0, 3])

    st.end()
  })

  t.end()
})
