const { Readable } = require('stream')

let limit = 10
const readable = new Readable({
  read() {
    if (limit--) {
      setTimeout(() => {
        this.push(`${limit}\n`)
      }, 1000)
    } else {
      this.push(null)
    }
  },
})

// enter flowing mode explicitly
readable.resume()

setTimeout(() => {
  // since the `data` event handler is attached after the stream has started to flow,
  // the first two chunks of data are missed
  readable.on('data', (data) => process.stdout.write(data))
}, 2000)
