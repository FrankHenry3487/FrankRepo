//
//  main.cpp
//  leetcode array3
//
//  Created by 张超 on 2018/9/26.
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
    int removeDuplicates(vector<int>& nums) {
        int idx_r = 1, idx_w = 0, dup_cnt = 0;
        int len = (int)nums.size();
        if (0 == len) return 0;
        for (; idx_r < len; idx_r++)
        {
            if (nums[idx_r] != nums[idx_w])
            {
                nums[++idx_w] = nums[idx_r];
                dup_cnt = 0;
            }
            else if (dup_cnt < 1)
            {
                nums[++idx_w] = nums[idx_r];
                dup_cnt++;
            }
            else{}
        }
        return idx_w + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
