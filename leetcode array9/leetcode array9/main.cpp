//
//  main.cpp
//  leetcode array9
//
//  Created by 张超 on 2018/10/3.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isVowel(char x)
    {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' ||
        x == 'E' || x == 'I' || x == 'O' || x == 'U';
    }
    
    string reverseVowels(string s) {
        int b = 0, e = (int)s.length() - 1;
        char tmp;
        while (b < e)
        {
            if (!isVowel(s[b]))
            {
                b++;
                continue;
            }
            if (!isVowel(s[e]))
            {
                e--;
                continue;
            }
            tmp = s[b];
            s[b++] = s[e];
            s[e--] = tmp;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    string s = "hello";
    Solution a;
    cout << a.reverseVowels(s);
    return 0;
}
