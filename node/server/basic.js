const http = require('http')

http.createServer((req, res) => {
  let body = ''
  req
    .setEncoding('utf8')
    .on('data', (chunk) => {
      body += chunk
    })
    .on('end', () => {
      let data
      try {
        data = JSON.parse(body)
      } catch (ex) {
        res.statusCode = 400
        res.end(`Error: ${ex.message}`)
        return
      }

      res.write(typeof data)
      res.end()
    })
}).listen(1337)
