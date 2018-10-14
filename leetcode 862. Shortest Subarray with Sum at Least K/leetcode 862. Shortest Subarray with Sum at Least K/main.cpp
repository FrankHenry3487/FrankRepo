//
//  main.cpp
//  leetcode 862. Shortest Subarray with Sum at Least K
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
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<int, int>> pq;
        pq.emplace(0,0);
        int size = (int)A.size(), sum = 0, res = -1;
        for (int i = 0; i < size; i++)
        {
            sum += A[i];
            while (pq.size() != 0 && sum + pq.top().first >= K)
            {
                if ((i - pq.top().second + 1) < res || res == -1)
                    res = i - pq.top().second + 1;
                pq.pop();
            }
            pq.emplace(-sum, i + 1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 2};
    Solution s;
    cout << s.shortestSubarray(a, 4);
    return 0;
}
