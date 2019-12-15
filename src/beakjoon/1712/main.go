package main

import (
	"fmt"
)

func main() {
	var A, B, C int	
	
	fmt.Scanf("%d %d %d", &A, &B, &C)

	var res int
	if B >= C {
		res = -1
	} else {
		res = A / (C - B) + 1	
	}
	
	fmt.Printf("%d\n", res)
}