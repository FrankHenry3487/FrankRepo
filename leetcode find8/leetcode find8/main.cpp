//
//  main.cpp
//  leetcode find8
//
//  Created by 张超 on 2018/10/12.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = (int)nums.size() - 1;
            while (j < k)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                if (k < (nums.size() - 1) && nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }
                int sum = nums[j] + nums[k];
                if (nums[i] + sum == 0)
                    res.push_back(vector<int>({nums[i], nums[j++], nums[k--]}));
                else if (nums[i] + sum > 0)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> a = {0, 0, 0, 0};
    (void)s.threeSum(a);
    return 0;
}
