// http://stackoverflow.com/a/31680811/4617270

function minPositiveSequenceSum(values: number[]): number {
  let minPositive = 0

  let maxSequence = 0
  let currentMaxSequence = 0

  let minSequence = 0
  let currentMinSequence = 0

  let indexFirstNegative = -1

  for (let k = 0; k < values.length; k++) {
    const value = values[k]

    if (value > 0) {
      if (minPositive === 0 || value < minPositive) {
        minPositive = value
      }
    } else if (indexFirstNegative === -1 && value < 0) {
      indexFirstNegative = k
    }

    currentMaxSequence += value
    if (currentMaxSequence < 0) {
      currentMaxSequence = 0
    } else if (currentMaxSequence > maxSequence) {
      maxSequence = currentMaxSequence
    }

    currentMinSequence += value
    if (currentMinSequence > 0) {
      currentMinSequence = 0
    } else if (currentMinSequence < minSequence) {
      minSequence = currentMinSequence
    }
  }

  if (minSequence === 0 || minPositive <= 1) {
    return minPositive
  }

  let minPositiveSequence = minPositive
  const offset = -minSequence
  const initialSequence: {[index: number]: boolean} = {}
  let valueCumulative = 0

  for (let k = 0; k < indexFirstNegative; k++) {
    const value = values[k]
    valueCumulative += value
    initialSequence[valueCumulative] = true
  }

  for (let k = indexFirstNegative; k < values.length; k++) {
    const value = values[k]

    valueCumulative += value
    initialSequence[valueCumulative] = true

    const indexHigh = valueCumulative - 1
    const indexLow = valueCumulative - minPositiveSequence + 1

    for (let index = indexHigh; index >= indexLow; index--) {
      if (initialSequence[index]) {
        minPositiveSequence = valueCumulative - index

        if (minPositiveSequence === 1) {
          return minPositiveSequence
        }

        break
      }
    }
  }

  return minPositiveSequence
}

function main() {
  const arr: number[] = [2, -3, 6, -2, -100, 100, 30, -2, -1, 0, 6, -2]
  console.log(minPositiveSequenceSum(arr))
}

main()
