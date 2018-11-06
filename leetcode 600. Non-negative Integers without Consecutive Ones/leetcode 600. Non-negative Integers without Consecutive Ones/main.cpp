//
//  main.cpp
//  leetcode 600. Non-negative Integers without Consecutive Ones
//
//  Created by 张超 on 2018/11/5.
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
    int findIntegers(int num) {
        int cnt = 1, cur = num;
        while(cur = cur >> 1)
            cnt++;
        if (cnt == 1) return num + 1;
        if (cnt == 2) return 3;
        vector<int> plat(cnt, 1), sat(cnt, 2);
        plat[1] = 2;
        sat[1] = 3;
        for (int i = 2; i < cnt; i++)
        {
            plat[i] = pow(2, i) + plat[i - 2];
            sat[i] = sat[i - 1] + sat[i - 2];
        }
        if (num >= plat[cnt - 1])
            return sat[cnt - 1];
        else
            return sat[cnt - 1] - plat[cnt - 1] + num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.findIntegers(16);
    return 0;
}
