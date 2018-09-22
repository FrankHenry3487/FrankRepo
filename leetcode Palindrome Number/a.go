package main

import "fmt"

func isPalindrome(x int) bool {
	var buffer [64] byte
	index := 0 
	if x < 0 {
		return false
	}  

	for{
		buffer[index] = byte(x % 10)
		index++
		x /= 10
		if x == 0 {
			break
		}
	}

	index2 := 0
	index--

	for{
		if buffer[index] != buffer[index2]{
			return false 
		}
		index--
		index2++
		if index <= index2 {
			break
		}
	}
	return true
}

func main() {
	fmt.Println(isPalindrome(123321))
}
