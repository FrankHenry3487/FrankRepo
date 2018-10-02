//
//  main.cpp
//  leetcode array11
//
//  Created by 张超 on 2018/10/3.
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
    int findNum(int s, vector<int>& nums, int idx)
    {
        int sum = 0;
        for (int i = idx; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum >= s)
                return i - idx + 1;
        }
        return (int)nums.size() + 1;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        int m_idx = 0, m_num = (int)nums.size() + 1, tmp;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp = findNum(s, nums, i);
            if (tmp < m_num)
            {
                m_idx = i;
                m_num = tmp;
            }
        }
        return m_num == ((int)nums.size() + 1) ? 0 : m_num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
