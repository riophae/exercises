function uniteSets(sets) {
  sets = sets.slice()
  const map = {}
  const ops = Array(sets.length).fill(-1)

  sets.forEach((set, setId) => {
    set.forEach((word) => {
      map[word] = (map[word] || []).concat(setId)
    })
  })

  Object.keys(map).forEach((word) => {
    if (map[word].length > 1) {
      const [to, ...from] = map[word].sort((a, b) => a - b)
      from.forEach(setId => ops[setId] = to)
    }
  })

  ops.forEach((to, from) => {
    if (to !== -1) {
      while (ops[to] !== -1) to = ops[to]
      sets[to] = sets[to].concat(
        sets[from].filter(word => !sets[to].includes(word)) // eslint-disable-line
      )
      sets[from] = null
    }
  })

  return sets.filter(Boolean)
}

function main() {
  const sets = [
    ['aaa', 'bbb', 'ccc'],
    ['bbb', 'ddd'],
    ['eee', 'fff'],
    ['ggg'],
    ['ddd', 'hhh'],
  ]
  console.log(uniteSets(sets))
}

main()
