const next = () => ({
  value: Math.random(),
  done: Math.random() > 0.75,
})

const iterable = {
  [Symbol.iterator]: () => ({ next }),
}

function* gen() {
  yield* iterable
}

console.log([...gen()])
