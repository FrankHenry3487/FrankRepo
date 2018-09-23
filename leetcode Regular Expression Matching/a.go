package main

import "fmt"

func equl(a byte, b byte) bool {
	if (a == '2' || b == '2') {
		return false
	}
	if ((a == '1' || b == '1') && a != b) {
		return false
	}
	if (a == '.' || b == '.' || a == b) {
		return true
	}
	return false
}

func isMatch(s string, p string) bool {
	s += "1"
	p += "1"
	index1 := 0
	index2 := 0
	star_cover := 0 
	var star byte = '2'
	for index1 < len(s) {
		if equl(s[index1], p[index2]) { //相等开始下一个字符匹配
			index2++
			index1++
			star_cover = 0
			continue
		} else if p[index2] == '*' {
			if equl(s[index1], p[index2 - 1]) { //*继续生效则p下标保持为*，尝试匹配下一个
                        	star_cover++      //被*吞掉一个
                      		star = p[index2 - 1] //*吞掉字符后缓存*的内容
                                index1++
                                continue
                         } else if equl(p[index2 + 1], s[index1]) {
                                index2 += 2
                                index1++
                                continue
                         } else if equl(star, p[index2 + 1]) {  //*后面还有相同字符已经被*吞掉要吐出来
                                index2++
                                continue
                        } else {
                                return false
 			}
		} else if p[index2 + 1] == '*' {
			index2 += 2
			continue
		} else if equl(p[index2], star) {
			if star_cover != 0 {
				star_cover--
				index2++
			} else if p[index2 + 1] == '*' {
				index2 += 2
			} else {
				return false
			}		
		}else {
			return false
		}
	}
	return true
}

func main() {
//	fmt.Println(isMatch("abcde", "abc*de"))
//	fmt.Println("expect true")
//	fmt.Println(isMatch("ab", "abc*de"))
//	fmt.Println("expect false")
//	fmt.Println(isMatch("abdeasdwd", "ab*"))
//	fmt.Println("expect false")
//	fmt.Println(isMatch("abdwqe", "abc*de"))
//    	fmt.Println("expect false")
	fmt.Println(isMatch("abddde", "ab.*de"))
    	fmt.Println("expect true")
	fmt.Println(isMatch("abbbbx", "abbbb"))
	fmt.Println("expect false")
	fmt.Println(isMatch("aa", "a"))
	fmt.Println("expect false")
	fmt.Println(isMatch("aaa", "c*a*a"))
	fmt.Println("expect true")
}
