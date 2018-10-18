//
//  main.cpp
//  leetcode find10
//
//  Created by 张超 on 2018/10/13.
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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = (int)A.size();
        vector<int> AB(size * size, 0);
        vector<int> CD(size * size, 0);
        int cnt = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                AB[i + j * size] = A[i] + B[j];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                CD[i + j * size] = C[i] + D[j];
        
        sort(AB.begin(), AB.end());
        sort(CD.begin(), CD.end());
        
        int i = 0, j = (int)CD.size() - 1;
        while (i < CD.size() && ~j)
        {
            if (AB[i] + CD[j] > 0)
                j--;
            else if (AB[i] + CD[j] < 0)
                i++;
            else
            {
                int up = 1, down = 1;
                while (i+1 < CD.size() && AB[i] == AB[i+1])
                {
                    i++;
                    up++;
                }
                while (~(j-1) && CD[j] == CD[j-1])
                {
                    j--;
                    down++;
                }
                cnt += up * down;
                i++;
                j--;
            }
        }
        return cnt;
    }
};
    
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> a = {-1,-1}, b = {-1,1}, c = {-1,1}, d = {1,-1};
    cout << s.fourSumCount(a, b, c, d);
    return 0;
}
