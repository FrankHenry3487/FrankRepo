//
//  main.cpp
//  leetcode Regular Expression Matching cpp
//
//  Created by 张超 on 2018/10/2.
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
    bool isMatch(string s, string p) {
        if (p.size() == 0)
            return s.size() == 0 ? true : false;
        
        bool res = false;
        
        if (0 != p.size() - 1 && p[1] == '*')
        {
            for (int j = 0; j < s.size() + 1; j++)
            {
                res |= isMatch(s.substr(j), p.substr(2));
                if (p[0] != '.' && p[0] != s[j])
                {
                    break;
                }
            }
        }
        else if (p[0] == '.')
        {
            if (s.size() == 0)
                return false;
            res = isMatch(s.substr(1), p.substr(1));
        }
        else
        {
            if (s.size() == 0)
            {
                return false;
            }
            if (s[0] != p[0])
            {
                return false;
            }
            res = isMatch(s.substr(1), p.substr(1));
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string s = "aa";
    string p = "a*";
    Solution a;
    cout << a.isMatch(s, p);
    return 0;
}
