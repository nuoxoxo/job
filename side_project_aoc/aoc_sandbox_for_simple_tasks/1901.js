let fs = require('fs')
let a = fs.readFileSync('_inputs_/1901.0').toString().split('\n')
let res = 0
let res2 = 0
for (let s of a){
	if (!s)
		break
	n = parseInt(s.trim())
	res += Math.floor(n / 3) - 2
	temp = Math.floor(n / 3) - 2
	while (temp > 0) {
		res2 += temp
		temp = Math.floor(temp / 3) - 2
	}
}
console.log(res, res2)
console.assert(res === 3159380)
console.assert(res2 === 4736213)
