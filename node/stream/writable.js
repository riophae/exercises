const { Writable } = require('stream')

const writable = new Writable()

writable._write = function (data, enc, next) { // eslint-disable-line no-underscore-dangle
  process.stdout.write(data.toString().toUpperCase())
  next()
}

writable.on('finish', () => process.stdout.write('FINISH\n'))

writable.write('a\n')
writable.write('b\n')
writable.write('c\n')

writable.end()
