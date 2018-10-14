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
    vector<vector<pair<int, int>>> fourSum(vector<pair<int, int>>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<pair<int, int>>> res;
        int size = (int)nums.size();
        if (size < 4) return res;
        for (int i = 0; i < size - 3; i++)
        {
            for (int n = size - 1; n > i + 2; n--)
            {
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    if (nums[i].first + nums[n].first + nums[j].first + nums[k].first == 0)
                        while (j != k)
                            res.push_back(vector<pair<int, int>>({nums[i], nums[j++], nums[k], nums[n]}));
                    else if (nums[i].first + nums[j].first + nums[k].first + nums[n].first > 0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return res;
    }
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<pair<int, int>> combine;
        for (int i = 0; i < A.size(); i++)
        {
            combine.emplace_back(A[i], 1);
            combine.emplace_back(B[i], 2);
            combine.emplace_back(C[i], 3);
            combine.emplace_back(D[i], 4);
        }
        vector<vector<pair<int, int>>> res = fourSum(combine);
        int cnt = 0;
        for(int i = 0; i < res.size(); i++)
        {
            if (res[i][1].second * res[i][2].second * res[i][3].second * res[i][4].second == 24)
                cnt++;
        }
        return cnt;
    }
};
    
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> a = {1,2}, b = {-2,-1}, c = {-1,2}, d = {0,2};
    s.fourSumCount(a, b, c, d);
    return 0;
}
