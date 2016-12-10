module.exports = function recoverSecret(triplets) {
  const deciphered = []

  let current = null // current triplet - an array of three chars
  const chars = [0, 1, 2].map(idx => () => current[idx])
  chars.forEach(char => char.isDeciphered = () => deciphered.includes(char()))
  const charsCurrentTripletDeciphered = () =>
    chars.reduce((total, char) => total + char.isDeciphered(), 0)

  function tryInsert(charX) {
    if (charX.isDeciphered()) {
      return {
        before() {},
        after() {},
      }
    }

    return {
      before(charY) {
        if (!charY.isDeciphered()) return

        let canInsert = false
        const posY = deciphered.indexOf(charY())

        if (posY === 0) {
          canInsert = true
        } else {
          canInsert = deciphered.slice(0, posY).every(charBeforeY =>
            !triplets.some(triplet => (
              triplet.includes(charX()) &&
              triplet.includes(charBeforeY) &&
              triplet.indexOf(charBeforeY) > triplet.indexOf(charX())
            ))
          )
        }

        if (canInsert) {
          deciphered.splice(posY, 0, charX())
        }
      },

      after(charY) {
        if (!charY.isDeciphered()) return

        let canInsert = true
        const posY = deciphered.indexOf(charY())

        if (posY === deciphered.length - 1) {
          canInsert = true
        } else {
          canInsert = deciphered.slice(posY + 1).every(charAfterY =>
            !triplets.some(triplet => (
              triplet.includes(charX()) &&
              triplet.includes(charAfterY) &&
              triplet.indexOf(charAfterY) < triplet.indexOf(charX())
            ))
          )
        }

        if (canInsert) {
          deciphered.splice(posY + 1, 0, charX())
        }
      },
    }
  }

  (function handleTriplet() {
    if (!triplets.length) return

    current = triplets.shift()

    if (!deciphered.length) {
      deciphered.push(...current)
    } else if (charsCurrentTripletDeciphered() > 0) {
      for (let i = 0; i < 3; i++) {
        for (let j = i + 1; j < 3; j++) tryInsert(chars[j]).after(chars[i])
        for (let k = 0; k < i; k++) tryInsert(chars[k]).before(chars[i])
      }
    }

    if (charsCurrentTripletDeciphered() !== 3) {
      triplets.push(current)
    }

    handleTriplet()
  }())

  return deciphered.join('')
}
