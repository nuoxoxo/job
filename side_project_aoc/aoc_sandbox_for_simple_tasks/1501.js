let fs = require('fs')
let input = fs.readFileSync('_inputs_/1501.1').toString().trim().split('')
let res = input.reduce((floor, c) => c == '(' ? ++floor : --floor, 0)
let floor = 0

// p2 golf
// let res2 = input.map(c => c == '(' ? ++floor : --floor).indexOf(-1) + 1

// p2 naive
floor = 0
i = -1
while (++i < input.length) {
	if (floor < 0)
		break
	floor = input[i] == '(' ? floor + 1 : floor - 1
}
res2 = i
console.log(res, res2)
