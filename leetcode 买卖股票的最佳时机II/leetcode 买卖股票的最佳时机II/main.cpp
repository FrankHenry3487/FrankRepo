//
//  main.cpp
//  leetcode 买卖股票的最佳时机II
//
//  Created by 张超 on 2018/10/27.
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
    int maxProfit(vector<int>& prices) {
        int res = 0, min = INT_MAX;
        for (auto& a : prices)
        {
            if (a < min)
                min = a;
            else
                res = max(a - min, res);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
