//
//  main.cpp
//  leetcode find5
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
    bool isAnagram(string s, string t) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        int len1 = (int)s.size(), len2 = (int)t.size();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++)
        {
            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt1[i] != cnt2[i])
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
