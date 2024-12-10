package main

import "fmt"

func main() {
	selection := 0
	x := 0
	fmt.Println("1. kor7")
	fmt.Println("2. kor8")
	fmt.Scanf("%d", &selection)
	if selection == 1 {
		fmt.Scanf("%d", &x)
	}
	n := 0
	fmt.Scanf("%d", &n)
	A := []int{}
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scanf("%d", &temp)
		A = append(A, temp)
	}
	if selection == 1 {
		kor7(x, A)
	} else {
		kor8(A)
	}
}

func kor7(x int, A []int) {
	// A := []int{5, 15, -30, 10, -5, 40, 10}
	length := len(A)
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			if A[i]+A[j] == x {
				fmt.Println("=", A[i], A[j])
			}
		}
	}
}

func kor8(A []int) {
	// A := []int{5, 15, -30, 10, -5, 40, 10}
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
