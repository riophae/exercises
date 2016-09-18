const { Readable } = require('stream')

const dataSource = ['a', 'b', 'c']
const readable = new Readable()
readable._read = function () {
  process.nextTick(() => {
    if (dataSource.length) {
      this.push(dataSource.shift())
    } else {
      this.push(null)
    }
  })
}

readable.pause() // enter paused mode

readable.on('data', data => process.stdout.write(`data: ${data}\n`))

// `readable.read()` will be called after `readable` event handler has been attached
readable.on('readable', () => {
  readable.read()
})
