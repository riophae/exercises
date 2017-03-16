// http://shiyanjun.cn/archives/823.html

const assert = require('assert')

class RadixSorter {
  readonly radix: number

  constructor() {
    this.radix = 10
  }

  sort(array: number[]) {
    const max = Math.max(...array)
    const counter = Array(this.radix)
    const bucket = []
    for (let i = 0; i < this.radix; i++) {
      bucket.push(Array(array.length).fill(0))
    }

    let temp = 1
    while (temp <= max) {
      ([].fill).call(counter, 0)

      for (let i = 0; i < array.length; i++) {
        const which = Math.floor(array[i] / temp) % this.radix
        bucket[which][counter[which]] = array[i]
        counter[which]++
      }

      temp *= this.radix
    }

    array.length = 0
    for (let i = 0; i < this.radix; i++) {
      for (let j = 0; j < counter[i]; j++) {
        array.push(bucket[i][j])
      }
    }
  }
}

function validate(arr) {
  for (let i = 1; i < arr.length; i++) {
    assert(arr[i - 1] <= arr[i])
  }
}

function main() {
  const array = [94, 12, 34, 76, 26, 9, 0, 37, 55, 76, 37, 5, 68, 83, 90, 37, 12, 65, 76, 100, 49]
  const sorter = new RadixSorter()
  sorter.sort(array)
  validate(array)
}

main()
