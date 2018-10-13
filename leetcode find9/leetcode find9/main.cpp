//
//  main.cpp
//  leetcode find9
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = (int)nums.size();
        if (size < 4) return res;
        for (int i = 0; i < size - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int n = size - 1; n > i + 2; n--)
            {
                if (n < size - 1 && nums[n] == nums[n + 1]) continue;
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1])
                    {
                        j++;
                        continue;
                    }
                    if (k < (n - 1) && nums[k] == nums[k + 1])
                    {
                        k--;
                        continue;
                    }
            
                    if (nums[i] + nums[n] + nums[j] + nums[k] == target)
                        res.push_back(vector<int>({nums[i], nums[j++], nums[k--], nums[n]}));
                    else if (nums[i] + nums[j] + nums[k] + nums[n] > target)
                        k--;
                    else
                        j++;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {1,-2,-5,-4,-3,3,3,5};
    Solution s;
    (void)s.fourSum(a, -11);
    return 0;
}
