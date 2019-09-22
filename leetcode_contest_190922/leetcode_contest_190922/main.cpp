//
//  main.cpp
//  leetcode_contest_190922
//
//  Created by 张超 on 2019/9/22.
//  Copyright © 2019 张超. All rights reserved.
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
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<long long> power = {1, 1, 1};
        vector<long long> num = {(long long)a, (long long)b, (long long)c};
        long long min_num = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            min_num = min(power[0]*num[0], power[1]*num[1]);
            min_num = min(min_num, power[2]*num[2]);
            for (int j = 0; j < 3; j ++) {
                if (power[j]*num[j] == min_num) power[j]++;
            }
        }
        return (int)min_num;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.nthUglyNumber(1000000000, 2, 217983653, 336916467);
    return 0;
}
