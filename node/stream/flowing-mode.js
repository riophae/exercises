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
  // since there are no `data` event handlers attached and no destinations piped to,
  // the data flowed in first two seconds are missed
  readable.on('data', (data) => process.stdout.write(data))
}, 2000)
