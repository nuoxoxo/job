package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	_"io/ioutil"
	"strconv"
)

var path string = "../_inputs/2205.1"
// var path string = "_inputs/2202.0"

func main() {
	data, err := os.Open(path)
	if err != nil {
		panic(err)
	}
	var a []string
	var op []string
	ok := false
	scanner := bufio.NewScanner(data)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		s := scanner.Text()
		if s == "" {
			ok = true
		}
		if ! ok {
			a = append(a, s)
		} else {
			op = append(op, s)
		}
	}
	enum := strings.Fields(a[len(a) - 1])
	tt, err := strconv.Atoi(enum[len(enum) - 1])
	if err != nil {
		panic(err)
	}w
	// fmt.Println(tt)
	a = a[:len(a) - 1]

}
