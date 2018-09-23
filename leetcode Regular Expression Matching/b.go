package main

import "fmt"

func isMatchInner(s string, p string, index1 int, index2 int) bool {
	if index2 >= len(p) {
		return true
	} else if index1 >= len(s) {
		return false 
	} else {
		return isMatch(string([]byte(s)[index1:]), string([]byte(p)[index2:]))
	}
}

func isMatch(s string, p string) bool {
	index := 0 
	star_cnt := 0
	for _, para := range p {
		if para == '*' {
			star_cnt++
		}
	}
	for ; index < len(p); index++ {
		if p[index] == '*' {
			match_flag := false
			for i := 0; i < (len(s) - len(p) + 1 + star_cnt); i++ {
				match_flag = match_flag || isMatchInner(s, p, index + i, index + 1)
			}
			return match_flag
		} else if index >= len(s) {
			return false
		} else if p[index] == '.' {
			continue
		} else {
			if s[index] != p[index] {
				return false
            }
		}
	}
	if index < len(s) {
		return false
	}
	return true
}

func main() {
	fmt.Println(isMatch("abcde", "abc*de"))
	fmt.Println("expect true")
	fmt.Println(isMatch("ab", "abc*de"))
	fmt.Println("expect false")
	fmt.Println(isMatch("abdeasdwd", "ab*"))
	fmt.Println("expect true")
	fmt.Println(isMatch("abdwqe", "abc*de"))
    	fmt.Println("expect false")
	fmt.Println(isMatch("abddde", "ab.*de"))
    	fmt.Println("expect true")
	fmt.Println(isMatch("abbbbx", "abbbb"))
	fmt.Println("expect false")
	fmt.Println(isMatch("aa", "a"))
	fmt.Println("expect false")
	fmt.Println(isMatch("aaa", "a*a*a"))
	fmt.Println("expect true")
}
