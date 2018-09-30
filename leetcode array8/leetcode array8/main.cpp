//
//  main.cpp
//  leetcode array8
//
//  Created by 张超 on 2018/9/30.
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
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int b = 0, e = (int)s.size() - 1;
        if (e < 0) return true;
        while (b < e)
        {
            if (!((s[b] >= '0' && s[b] <= '9') || (s[b] >= 'a' && s[b] <= 'z')))
            {
                b++;
            }
            else if (!((s[e] >= '0' && s[e] <= '9') || (s[e] >= 'a' && s[e] <= 'z')))
            {
                e--;
            }
            else if (s[b] != s[e])
            {
                return false;
            }
            else
            {
                b++;
                e--;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution a;
    cout << a.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
