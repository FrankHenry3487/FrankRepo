//
//  main.cpp
//  leetcode Weekly Contest 109
//
//  Created by 张超 on 2018/11/4.
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
    int shortestBridge(vector<vector<int>>& A) {
        bool is_found = false, is_over = false;
        vector<vector<int>> cp(A);
        int res = 3;
        while(!is_over)
        {
            is_over = true;
            for (int i = 0; i < A.size(); i++)
                for (int j = 0; j < A.size(); j++)
                {
                    if ((A[i][j] == 1 && !is_found) || A[i][j] == 2)
                    {
                        A[i][j] = 2;
                        is_found = true;
                        if (i > 0 && A[i - 1][j] == 1)
                        {
                            A[i - 1][j] = 2;
                            is_over = false;
                        }
                        if (i < A.size() - 1 && A[i + 1][j] == 1)
                        {
                            A[i + 1][j] = 2;
                            is_over = false;
                        }
                        if (j > 0 && A[i][j - 1] == 1)
                        {
                            A[i][j - 1] = 2;
                            is_over = false;
                        }
                        if (j < A.size() - 1 && A[i][j + 1] == 1)
                        {
                            A[i][j + 1] = 2;
                            is_over = false;
                        }
                    }
                }
        }
        while(1)
        {
            for (int i = 0; i < A.size(); i++)
                for (int j = 0; j < A.size(); j++)
                {
                    if (A[i][j] == res - 1)
                    {
                        cp[i][j] = res;
                        if (i > 0)
                        {
                            if (A[i - 1][j] != 1)
                                cp[i - 1][j] = res;
                            else
                                return res - 3;
                        }
                        if (i < A.size() - 1)
                        {
                            if (A[i + 1][j] != 1)
                                cp[i + 1][j] = res;
                            else
                                return res - 3;
                        }
                        if (j > 0)
                        {
                            if (A[i][j - 1] != 1)
                                cp[i][j - 1] = res;
                            else
                                return res - 3;
                        }
                            
                        if (j < A.size() - 1)
                        {
                            if (A[i][j + 1] != 1)
                                cp[i][j + 1] = res;
                            else
                                return res - 3;
                        }
                    }
                }
            A.assign(cp.begin(), cp.end());
            res++;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> A = {{0,0,0,1,0,0,0,1},{0,0,0,1,1,0,1,1},{0,1,1,1,0,0,1,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    cout << s.shortestBridge(A);
    return 0;
}
