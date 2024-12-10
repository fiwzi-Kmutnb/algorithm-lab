package main

import "fmt"

func main() {
	fmt.Println("kor7: ")
	kor7()
	fmt.Println("-----------------")
	fmt.Println("kor8: ")
	kor8()
}

func kor7() {
	x := 20
	A := []int{5, 15, -30, 10, -5, 40, 10}
	length := len(A)
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			if A[i]+A[j] == x {
				fmt.Println(A[i], A[j])
			}
		}
	}
}

func kor8() {
	A := []int{5, 15, -30, 10, -5, 40, 10}
	length := len(A)
	maxSum := A[0]
	start := 0
	end := 0
	for i := 0; i < length; i++ {
		for j := i; j < length; j++ {
			currentSum := 0
			for k := i; k <= j; k++ {
				currentSum += A[k]
			}
			if currentSum > maxSum {
				maxSum = currentSum
				start = i
				end = j
			}
		}
	}
	fmt.Println(A[start : end+1])
	fmt.Println(maxSum)
}
