//
//  main.cpp
//  leetcode find6
//
//  Created by 张超 on 2018/10/11.
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
#include <set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char rep1[256] = {0};
        char rep2[256] = {0};
        int len1 = (int)s.size(), len2 = (int)t.size();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++)
        {
            int tmp1 = (int)s[i], tmp2 = (int)t[i];
            if (rep1[tmp1] == 0)
                rep1[tmp1] = tmp2;
            else if (rep1[tmp1] != tmp2)
                return false;
            
            if (rep2[tmp2] == 0)
                rep2[tmp2] = tmp1;
            else if (rep2[tmp2] != tmp1)
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string s = "aa";
    string t = "ab";
    Solution S;
    cout << S.isIsomorphic(s, t);
    return 0;
}
