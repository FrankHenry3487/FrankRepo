//
//  main.cpp
//  leetcode 不同路径
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
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        
        vector<int> one_row(n - 1, 0);
        vector<vector<int>> mat(m - 1, one_row);
        
        for (int i = 0; i < m - 1; i++)
            mat[i][0] = i + 2;
        for (int i = 1; i < n - 1; i++)
            mat[0][i] = i + 2;
        for (int i = 1 ; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
        return mat[m - 2][n - 2];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.uniquePaths(1, 2);
    return 0;
}
