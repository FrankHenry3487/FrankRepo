package main

import "fmt"

func main() {
	fmt.Println(myAtoi("9223372036854775808"))
}

func myAtoi(str string) int {
	var out int = 0 
	i := 0
	flag := false 
	
	for ; i < len(str); i++{
		if str[i] == ' '{
			continue
		}else{
			break
		}
	}
	
	if (i == len(str)){
		return out
	}

	if (str[i] == '-'){
		flag = true
		i++
	}else if str[i] == '+' {
		i++
	}

	for ; i < len(str); i++{
		if (str[i] >= '0' && str[i] <= '9'){
			out *= 10
			out += int(str[i]) - int('0')
			if (out > 2147483648 && flag) {
				return -2147483648
			}else if (out > 2147483647 && !flag) {
				return 2147483647
			}
		}else{
			break
		}
	}
	
	if flag {
		out = -out
	}
	
	return out
}
