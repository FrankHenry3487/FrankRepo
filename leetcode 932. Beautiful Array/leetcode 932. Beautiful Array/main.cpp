//
//  main.cpp
//  leetcode 932. Beautiful Array
//
//  Created by 张超 on 2018/10/29.
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
    vector<int> res;
public:
    void dfs(int current, int max)
    {
        if (current > max) return;
        dfs(2*current, max);
        res.push_back(current);
        dfs(2*current + 1, max);
    }
    vector<int> beautifulArray(int N) {
        dfs(1, N);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
