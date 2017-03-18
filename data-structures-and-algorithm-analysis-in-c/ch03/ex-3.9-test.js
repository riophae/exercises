const { test } = require('tap')
const { PolynomialNumber } = require('./ex-3.9')

test('basic', (t) => {
  const pn1 = new PolynomialNumber(4, 2)
  t.equal(pn1.output(), '20000')

  const pn2 = new PolynomialNumber(1, 8)
  pn2.next = pn1
  t.equal(pn2.output(), '20080')

  pn2.exponent = 0
  t.equal(pn2.output(), '20008')

  const pn3 = PolynomialNumber.createFromArgList([[0, 9], [3, 1], [8, 2], [10, 9], [20, 3]])
  t.equal(pn3.output(), '300000000090200001009')

  t.end()
})

test('add', (t) => {
  const pn1 = PolynomialNumber.createFromArgList([[0, 9]])
  const sum1 = PolynomialNumber.add(pn1, pn1)
  t.equal(sum1.output(), '18')

  const pn2 = PolynomialNumber.createFromArgList([[0, 9], [1, 9]])
  const sum2 = PolynomialNumber.add(pn1, pn2)
  t.equal(sum2.output(), '108')

  const pn3 = PolynomialNumber.createFromArgList([[0, 9], [1, 9], [2, 9], [3, 9]])
  const pn4 = new PolynomialNumber(0, 1)
  const sum3 = PolynomialNumber.add(pn3, pn4)
  t.equal(sum3.output(), '10000')

  const pn5 = PolynomialNumber.createFromArgList([[4, 5], [7, 1]])
  const pn6 = PolynomialNumber.createFromArgList([[4, 5], [5, 2]])
  const sum4 = PolynomialNumber.add(pn5, pn6)
  t.equal(sum4.output(), '10300000')

  t.end()
})
