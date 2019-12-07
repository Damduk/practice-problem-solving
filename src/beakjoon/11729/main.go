package main

import (
	"fmt"
)

type result struct {
	src int
	dest int
}

var output []result

func main() {
	var n int
	
	fmt.Scanf("%d", &n)
	
	hanoi(1, 3, 2, n)
	
	fmt.Println(len(output))
	for _, out := range output {
		fmt.Printf("%d %d\n", out.src, out.dest)
	}
}

func hanoi(src, dest, tmp int, num int) {
	if (num < 1) {
		return
	}
	
	hanoi(src, tmp, dest, num - 1)
	
	output = append(output, result{ src, dest })
	
	hanoi(tmp, dest, src, num - 1)
}
