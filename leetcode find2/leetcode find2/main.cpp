//
//  main.cpp
//  leetcode find2
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
#include <set>

using namespace std;

class Solution {
public:
    int nextStep(int num)
    {
        int res = 0;
        while (num)
        {
            res += pow(num % 10, 2);
            num /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        vector<bool> t(200, false);
        int idx = 0;
        while (1) {
            idx = nextStep(n);
            if (idx == 1) return true;
            if (idx < 199)
            {
                if (t[idx] == true)
                {
                    return false;
                }
                t[idx] = true;
            }
            n = idx;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.isHappy(19);
    return 0;
}
