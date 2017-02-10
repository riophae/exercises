const { test } = require('tap')
const {
  compose, flip,
  concat, map, filter, reduce, join, sortBy, head, last,
  add,
  prop,
  replace, toLower,
} = require('ramda')
const accounting = require('accounting')

const CARS = [
  { name: 'Ferrari FF', horsepower: 660, dollar_value: 700000, in_stock: true },
  { name: 'Spyker C12 Zagato', horsepower: 650, dollar_value: 648000, in_stock: false },
  { name: 'Jaguar XKR-S', horsepower: 550, dollar_value: 132000, in_stock: false },
  { name: 'Audi R8', horsepower: 525, dollar_value: 114200, in_stock: false },
  { name: 'Aston Martin One-77', horsepower: 750, dollar_value: 1850000, in_stock: true },
  { name: 'Pagani Huayra', horsepower: 700, dollar_value: 1300000, in_stock: false },
]

test('exercise-1', (t) => {
  const isLastInStock = compose(prop('in_stock'), last)

  const value = isLastInStock(CARS)
  const expected = false
  t.equal(value, expected)
  t.end()
})

test('exercise-2', (t) => {
  const nameOfFirstCar = compose(prop('name'), head)

  const value = nameOfFirstCar(CARS)
  const expected = 'Ferrari FF'
  t.equal(value, expected)
  t.end()
})


test('exercise-3', (t) => {
  const _average = xs => reduce(add, 0, xs) / xs.length
  const averageDollarValue = compose(_average, map(prop('dollar_value')))

  const value = averageDollarValue(CARS)
  const expected = 790700
  t.equal(value, expected)
  t.end()
})

test('exercise-4', (t) => {
  const _underscore = replace(/\W+/g, '_')
  const sanitizeNames = map(compose(toLower, _underscore))

  const value = sanitizeNames(['Hello World'])
  const expected = ['hello_world']
  t.deepEqual(value, expected)
  t.end()
})

test('bonus-1', (t) => {
  const formatMoney = compose(accounting.formatMoney, prop('dollar_value'))
  const availableCars = filter(prop('in_stock'))
  const availablePrices = compose(join(', '), map(formatMoney), availableCars)

  const value = availablePrices(CARS)
  const expected = '$700,000.00, $1,850,000.00'
  t.equal(value, expected)
  t.end()
})

test('bonus-2', (t) => {
  const append = flip(concat)
  const fastestCar = compose(
    append(' is the fastest'),
    prop('name'),
    last,
    sortBy(prop('horsepower')),
  )

  const value = fastestCar(CARS)
  const expected = 'Aston Martin One-77 is the fastest'
  t.equal(value, expected)
  t.end()
})
