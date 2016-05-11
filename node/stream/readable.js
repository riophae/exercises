const { Readable } = require('stream')

class ToReadable extends Readable {
  constructor(iterable) {
    super()
    this.iterator = (function* () {
      yield* iterable
    }())
  }

  _read() {
    const res = this.iterator.next()
    if (res.done) {
      this.push(null)
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
readable.on('data', (data) => process.stdout.write(data))
readable.on('end', () => process.stdout.write('DONE\n'))
