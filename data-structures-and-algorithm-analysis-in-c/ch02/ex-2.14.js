class LinkedList {
  constructor(data, next = null) {
    this.data = data
    this.next = next
  }

  append(data) {
    this.next = new LinkedList(data)
    return this.next
  }

  toArray() {
    const arr = []
    let node = this
    while (node && node.value !== null) {
      arr.push(node.data)
      node = node.next
    }
    return arr
  }
}

function findPrimesLessThan(n) {
  const head = new LinkedList(2)
  let node

  node = head
  let i = 1
  while (++i <= n) {
    node = node.append(i)
  }

  node = head
  while (node && node.data < Math.sqrt(n)) {
    let prev = node
    let curr = prev.next

    while (curr) {
      if (curr.data % node.data === 0) {
        prev.next = curr.next
      } else {
        prev = curr
      }

      curr = curr.next
    }

    node = node.next
  }

  return head.toArray()
}

function main() {
  console.log(findPrimesLessThan(128))
}

main()
