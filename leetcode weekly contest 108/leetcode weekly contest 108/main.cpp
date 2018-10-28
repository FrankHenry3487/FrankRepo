//
//  main.cpp
//  leetcode weekly contest 108
//
//  Created by 张超 on 2018/10/28.
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
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = (int)A.size(), res = INT_MAX;
        vector<vector<int>> out(size, vector<int>(size, INT_MAX));
        for (int i = 0; i < size; i++)
            out[0][i] = A[0][i];
        for (int i = 1; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = max(j - 1, 0); k < min(size, j + 2); k++)
                    out[i][j] = min(out[i][j], out[i - 1][k] + A[i][j]);
        for (auto &v : out[size - 1])
            res = min(v, res);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3};
    vector<int> b = {4,5,6};
    vector<int> c = {7,8,9};
    vector<vector<int>> A = {a,b,c};
    Solution s;
    
    cout << s.minFallingPathSum(A);
    return 0;
}
