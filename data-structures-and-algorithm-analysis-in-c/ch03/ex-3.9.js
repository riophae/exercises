const assert = require('assert')

class PolynomialNumber {
  constructor(exponent = -1, digit = 0) {
    this.digit = digit
    this.exponent = exponent
    this.next = null
  }

  output() {
    let output = ''
    let e = 0
    let pointer = this

    while (pointer) {
      while (pointer.exponent > e++) {
        output = '0' + output
      }
      output = pointer.digit + output
      pointer = pointer.next
    }

    return output
  }

  static createFromArgList(argList) {
    return argList.reduceRight((next, [exponent, coefficient]) => {
      const curr = new PolynomialNumber(exponent, coefficient)
      curr.next = next
      return curr
    }, null)
  }

  static _validate(p) {
    let prev = p
    p = p.next
    if (p !== null) {
      assert(prev.digit > 0 && prev.digit < 10)
    }
    while (p) {
      assert(prev.exponent < p.exponent)
      assert(p.digit > 0 && p.digit < 10)
      prev = p
      p = p.next
    }
  }

  static _insert(p, exponent, digit) {
    assert(p.exponent <= exponent)

    if (p.exponent === exponent) {
      digit = p.digit += digit
    } else if (p.next === null) {
      p = p.next = new PolynomialNumber(exponent, digit)
    } else if (p.next.exponent === exponent) {
      PolynomialNumber._insert(p.next, exponent, digit)
    } else {
      const temp = p.next
      p = p.next = new PolynomialNumber(exponent, digit)
      p.next = temp
    }

    if (digit >= 10) {
      p.digit -= 10
      assert(p.digit < 10)
      if (p.digit === 0) {
        p.exponent += 1
        p.digit = 1
      } else {
        PolynomialNumber._insert(p, exponent + 1, 1)
      }
    }
  }

  static add(a, b) {
    const result = new PolynomialNumber()
    let p = result

    while (a || b) {
      let e
      let d

      if (b === null || (a !== null && a.exponent < b.exponent)) {
        e = a.exponent
        d = a.digit
        a = a.next
      } else if (a === null || (b !== null && a.exponent > b.exponent)) {
        e = b.exponent
        d = b.digit
        b = b.next
      } else {
        e = a.exponent
        d = a.digit + b.digit
        a = a.next
        b = b.next
      }

      PolynomialNumber._insert(p, e, d)
      p = p.next === null ? p : p.next
    }

    PolynomialNumber._validate(result.next)
    return result.next
  }

  static subtract() {
  }

  static multiply() {
  }

  static divide() {
  }
}

module.exports = {
  PolynomialNumber,
}
