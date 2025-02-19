package main

import (
	"fmt"
)

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func ConvertResult(r [][]int) []string {
	ss := make([]string, len(r))

	for j, rr := range r {
		for i := 0; i < len(rr); i++ {
			if rr[i] == 0 {
				ss[j] += "."
			} else {
				ss[j] += "Q"
			}
		}
	}

	return ss
}

func IsGood(size, row, col int, result [][]int) bool {
	if col == size {
		return false
	}

	for i := 0; i < row; i++ {
		if result[i][col] == 1 {
			return false
		}
	}

	j := col - 1
	for i := row - 1; i >= 0 && j >= 0; i-- {
		if result[i][j] == 1 {
			return false
		}
		j--
	}

	j = col + 1
	for i := row - 1; i >= 0 && j < size; i-- {
		if result[i][j] == 1 {
			return false
		}
		j++
	}

	return true
}

func ClearResult(r [][]int) {
	for _, rr := range r {
		for i := 0; i < len(rr); i++ {
			rr[i] = 0
		}
	}
}

func NQueensSolutions(size, row int, result [][]int, final *[][]string) {
	if row == size {
		return
	}

	for col := 0; col < size; col++ {
		result[row][col] = 1
		if IsGood(size, row, col, result) {
			if row == size-1 {
				*final = append(*final, ConvertResult(result))
			}
			NQueensSolutions(size, row+1, result, final)
		}
		result[row][col] = 0
	}
}

func GetNQueensSolutions(n int) [][]string {
	r := make([][]int, n)
	for i := 0; i < n; i++ {
		r[i] = make([]int, n)
	}
	ClearResult(r)

	result := [][]string{}
	NQueensSolutions(n, 0, r, &result)
	return result
}

func main() {
	for {
		fmt.Print("Please enter the size of the maze: ")
		var size int
		fmt.Scan(&size)
		if size == 0 {
			break
		}

		result := GetNQueensSolutions(size)
		fmt.Println(result)
	}
}
