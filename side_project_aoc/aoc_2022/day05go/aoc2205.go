package main

import (
	"fmt"
	_"bufio"
	_"os"
	"strings"
	"io/ioutil"
	_"strconv"
)

var path string = "../_inputs/2205.1"

func main() {

	data2, err := ioutil.ReadFile(path)
	if err != nil {
		panic(err)
	}
	var A []string
	var i int
	lines := string(data2)
	A = strings.Split(lines, "\n\n")
	// A[0]: piles of crates: str
	// A[1]: operations inst: str
	C := strings.Split(A[0], "\n") // Crates
	tt := int(C[len(C) - 1][len(C[len(C) - 1]) - 2]) - 48
	fmt.Printf("%T", tt)
	//i = 0
	// tt: how many piles of crates
	c1 := [tt][]int
	c2 := [tt][]int
	/*
	for _, s := range(C) {
		i = 0
		for i < tt {
			r := s[1 + 4 * i]
			c1 = append(c1, r)
			c2 = append(c2, r)
		}
	}*/
	fmt.Println(c1)
	fmt.Println(c1)

}
