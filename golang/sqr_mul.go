package main

import (
	"fmt"
)

type operation string

const (
	square   operation = "SQUARE"
	multiply           = "MULTIPLY"
)

func perform_operation(op operation, x uint, p uint) uint {
	switch op {
	case square:
		return x * x
	case multiply:
		return p * x
	}
	return 0
}

func reverse(x uint) (rev uint) {
	for x != 0 {
		rev = rev << 1
		rev = rev | (x & 1)
		x = x >> 1
	}
	return
}

//calculate x^y mod z using square and multiply algorithm
func calculate_mod(x, y, z uint) uint {
	//covering few base cases
	if y == 0 {
		return 1
	}
	if y == 1 {
		return x % z
	}
	var opSequence []operation
	//the algorithm needs to go from most to least significant bit so we do the reverse as its easy to go from LSB
	//the last bit(of reversed i.e first bit of normal) is removed as we already start from x and not 1
	temp := reverse(y) >> 1
	for temp > 0 {
		val := temp & 1
		opSequence = append(opSequence, square)
		if val == 1 {
			opSequence = append(opSequence, multiply)
		}
		temp = temp >> 1
	}
	p := x
	for _, op := range opSequence {
		x = perform_operation(op, x, uint(p)) % z
	}
	return x
}

func main() {
	var x, y, z uint
	fmt.Println("Enter x,y and z in order where x^y mod z is to be calculated")
	fmt.Scanf("%d %d %d", &x, &y, &z)
	fmt.Printf("%d^%d mod %d = %d\n", x, y, z, calculate_mod(x, y, z))
}
