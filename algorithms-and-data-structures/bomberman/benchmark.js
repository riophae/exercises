const { Suite } = require('benchmark')

const basic = require('./basic')
const reversed = require('./reversed')

new Suite()
.add('basic', () => {
  basic()
})
.add('reversed', () => {
  reversed()
})
.on('cycle', (evt) => {
  console.log(evt.target)
})
.on('complete', function () {
  console.log(`Fastest is ${this.filter('fastest').map('name')}`)
})
.run()
