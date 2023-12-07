function adding(left: number, right: number): number {
	return left+ right
}

console.log(adding(parseInt(process.argv[2]), parseInt(process.argv[3])))
