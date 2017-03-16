const assert = require('assert')

function toPostfix(expr) {
  const output = []
  const ops = []

  const priorityMap = {
    '+': 1,
    '-': 1,
    '*': 10,
    '/': 10,
    '(': 100,
    ')': 100,
  }

  const numberRe = /^\d+$/
  const opRe = /^[+\-*/()]$/
  const re = /\s+|\d+|[+\-*/()]/g

  let matchResult
  while (matchResult = re.exec(expr)) {
    const component = matchResult[0]
    if (numberRe.test(component)) {
      output.push(parseFloat(component))
    } else if (opRe.test(component)) {
      if (component === ')') {
        let op
        while (ops.length && (op = ops.pop(), op !== '(')) {
          output.push(op)
        }
      } else {
        const p = priorityMap[component]
        while (ops.length && priorityMap[ops[ops.length - 1]] >= p && ops[ops.length - 1] !== '(') {
          output.push(ops.pop())
        }
        ops.push(component)
      }
    }
  }

  while (ops.length) {
    output.push(ops.pop())
  }

  return output
}

function evaluateExpression(expr) {
  const postfix = toPostfix(expr)
  const stack = []

  while (postfix.length) {
    const c = postfix.shift()

    if (typeof c === 'number') {
      stack.push(c)
    } else {
      switch (c) {
        case '+': stack.push(stack.pop() + stack.pop()); break
        case '-': stack.push(-stack.pop() + stack.pop()); break
        case '*': stack.push(stack.pop() * stack.pop()); break
        case '/': stack.push(1 / stack.pop() * stack.pop()); break
        default: throw new Error('Unexpected input')
      }
    }
  }

  return stack.pop()
}

function main() {
  const expr = '3 + 4 * 2 - (5 + 4 / 2)'
  const result = evaluateExpression(expr)
  const expected = 4
  assert.strictEqual(result, expected)
}

main()
