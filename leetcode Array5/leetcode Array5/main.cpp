//
//  main.cpp
//  leetcode Array5
//
//  Created by 张超 on 2018/9/29.
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
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {3,2,3,1,2,4,5,5,6};
    Solution m;
    cout << m.findKthLargest(a, 4);
    return 0;
}
