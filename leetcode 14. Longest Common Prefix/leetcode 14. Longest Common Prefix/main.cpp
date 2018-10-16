//
//  main.cpp
//  leetcode 14. Longest Common Prefix
//
//  Created by 张超 on 2018/10/16.
//  Copyright © 2018 张超. All rights reserved.
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
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        bool is_continue = true;
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        while (1)
        {
            char tmp = strs[0][idx];
            if (tmp == 0) break;
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i][idx] != tmp)
                {
                    is_continue = false;
                    break;
                }
            }
            if (is_continue)
                idx++;
            else
                break;
        }
        return strs[0].substr(0, idx);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
