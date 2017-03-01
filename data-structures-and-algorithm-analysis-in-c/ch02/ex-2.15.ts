function pow(x: number, exp: number) {
  const powers: {[index: number]: number} = {
    0: 1,
    1: x,
  }
  let multi = 0

  function calc(e) {
    if (typeof powers[e] === 'number') {
      return powers[e]
    }

    if (e % 2 === 0) {
      powers[e / 2] = calc(e / 2)
      powers[e] = powers[e / 2] * powers[e / 2]
      multi++
    } else {
      const e1 = Math.floor(e / 2)
      const e2 = e - e1
      powers[e1] = calc(e1)
      powers[e2] = calc(e2)
      powers[e] = powers[e1] * powers[e2]
      multi++
    }

    return powers[e]
  }

  const result = calc(exp)
  console.log(`Total: ${multi} multiplications.`)
  return result
}

function main() {
  console.log(pow(2, 62))
}

main()
