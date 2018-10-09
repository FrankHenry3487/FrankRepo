//
//  main.cpp
//  leetcode 918. Maximum Sum Circular Subarray
//
//  Created by 张超 on 2018/10/8.
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
    int maxSubarraySumCircular(vector<int>& A) {
        int max = INT_MIN, total = 0, tmp;
        int size = (int)A.size();
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, 0);
        for (int i = 1; i <= 2 * size; i++)
        {
            total += A[(i - 1) % size];
            while (i - pq.top().second > size)
                pq.pop();
            tmp = pq.top().first + total;
            max = max > tmp ? max : tmp;
            pq.emplace(-total, i);
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> A = {8,-1,-3,8,-6,-9,2,4};
    cout << s.maxSubarraySumCircular(A);
    return 0;
}
