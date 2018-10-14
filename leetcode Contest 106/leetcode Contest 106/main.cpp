//
//  main.cpp
//  leetcode Contest 106
//
//  Created by 张超 on 2018/10/14.
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
    int minAddToMakeValid(string S) {
        int cnt_tmp = 0;
        int cnt = 0;
        for (int i = 0; i < S.size(); i++)
        {
            switch (S[i]) {
            case '(':
                if (cnt_tmp <= 0)
                    cnt_tmp--;
                else {
                    cnt += cnt_tmp;
                    cnt_tmp = -1;
                }
                break;
                case ')':
                    cnt_tmp++;
                    break;
            }
        }
        return cnt + abs(cnt_tmp);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.minAddToMakeValid("(((");
    return 0;
}
