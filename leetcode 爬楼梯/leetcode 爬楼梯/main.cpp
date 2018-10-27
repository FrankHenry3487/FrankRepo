//
//  main.cpp
//  leetcode 爬楼梯
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
    int climbStairs(int n) {
        vector<int> ways(n, 1);
        ways[1] = 2;
        for(int i = 2; i < n; i++)
            ways[i] = ways[i - 1] + ways[i - 2];
        return ways[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
