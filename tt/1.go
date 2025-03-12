package main

import "fmt"

func printArray(A []int) {
	fmt.Println(A)
}

func divideAndConquer(A []int) {
	if len(A) <= 1 {
		printArray(A)
		return
	}
	mid := len(A) / 2
	left := A[:mid]
	right := A[mid:]
	divideAndConquer(left)
	divideAndConquer(right)
}

func main() {
	A := []int{5, 15, -30, 10, -5, 40, 10}
	divideAndConquer(A)
}
