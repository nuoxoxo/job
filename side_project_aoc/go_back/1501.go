package main

import (
	"fmt"
	"strings"
	"io/ioutil"
)

var path string = "_inputs_/1501.0"

func main() {

	data, err := ioutil.ReadFile(path)
	if err != nil { panic(err) }

	var line string = string(data)
	line = strings.Replace(line, "\n", "", -1) // line.strip()

	var res, res2 int = 0, 0
	var base bool = false
	_, _ = res, res2
	for i, c := range line {
		if ! base && res < 0 {
			res2 = i
			base = true
		}
		if c == '(' {
			res++
		}else {
			res--
		}
	}
	fmt.Println("Star 1:", res)
	fmt.Println("Star 2:", res2)
}
