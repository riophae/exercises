const express = require('express')

express()
  .use(express.static('web', { index: 'index.htm' }))
  .listen(3000)
