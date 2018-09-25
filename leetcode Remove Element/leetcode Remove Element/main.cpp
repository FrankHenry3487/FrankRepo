//
//  main.cpp
//  leetcode Remove Element
//
//  Created by 张超 on 2018/9/25.
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
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> num = {0,1,2,2,3,0,4,2};
    Solution a;
    cout << a.removeElement(num, 2) <<endl;
    cout << num[0] <<"  " << num[1] <<"  " << num[2] <<"  " << num[3] <<endl;
    return 0;
}
