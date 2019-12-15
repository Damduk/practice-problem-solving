package main

import (
	"fmt"
	"sort"
)

type point struct {
	X int
	Y int
}

type cmpFunc func(i, j int) bool

func main() {
	var n int

	fmt.Scanf("%d", &n)

	arr := make([]point, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d", &arr[i].X, &arr[i].Y)
	}
	
	sort.Slice(arr, bindPointPriorityFunc(arr))

	for _, p := range arr {
		fmt.Println(p.X, p.Y)
	}
}

func bindPointPriorityFunc(arr []point) cmpFunc {
	return func(i, j int) bool {
		if (arr[i].Y == arr[j].Y) {
			return arr[i].X < arr[j].X
		}
		
		return arr[i].Y < arr[j].Y 
	}
}
