//
//  main.cpp
//  leetcode Smallest Range II
//
//  Created by 张超 on 2018/9/24.
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

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        unsigned long n = A.size();
        
        if (n == 1)
        {
            return 0;
        }
        
        int res = A[n - 1] - A[0];
        
        for (int i = 0; i < A.size() - 1; i++)
        {
            res = min(res, max(A[n - 1] - K, A[i] + K) - min(A[0] + K, A[i + 1] - K));
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {7, 8, 8};
    Solution b;
    cout << b.smallestRangeII(a, 5);
    return 0;
}
