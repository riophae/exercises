const { Readable } = require('stream')

class ToReadable extends Readable {
  constructor(iterable) {
    super()
    this.iterator = (function* () {
      yield* iterable
    }())
    this.isFirst = true
  }

  _read() {
    if (this.isFirst) {
      this.isFirst = false
      console.log('first read')
    }

    const res = this.iterator.next()
    if (res.done) {
      this.push(null)
      console.log('drained')
      process.nextTick(() => {
        console.log('next tick after drained')
      })
    } else {
      setTimeout(() => {
        this.push(`${res.value}\n`)
      }, 250)
    }
  }
}

const iterable = (function* (limit) {
  while (limit--) { // eslint-disable-line no-param-reassign
    yield Math.random()
  }
}(25))

const readable = new ToReadable(iterable)

console.log('stand by')
readable.on('data', (data) => process.stdout.write(data))
console.log('`data` event handler has been attached')
readable.on('end', () => process.stdout.write('DONE\n'))
console.log('`end` event handler has been attached')

process.nextTick(() => {
  console.log('next tick after event handlers have been attached')
})
