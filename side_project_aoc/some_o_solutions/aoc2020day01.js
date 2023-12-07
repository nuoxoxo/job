const fs = require('fs');
const lines = fs.readFileSync('2001.txt').toString().split('\n')
const numberArr = lines.map(Number);

// Part 1

let partOne = arr => {
  let numberSet = new Set()
  for (let number of arr) {
    let diff = 2020 - number
    if (numberSet.has(diff)) {
      console.log(number * diff)
    }
    numberSet.add(number)
  }
}

// Part 2 

let partTwo = arr => {
  let pairsum = {}
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      let sum = arr[i] + arr[j]
      pairsum[sum] = [ arr[i], arr[j] ]
    }
  }

  for (let number of arr) {
    const diff = 2020 - number
    if (diff in pairsum) {
      let a, b
      [ a, b ] = pairsum[diff]
      console.log(number * a * b)
      break
    }
  }
}

// Driver

partOne(numberArr)
partTwo(numberArr)
