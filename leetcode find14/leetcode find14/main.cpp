//
//  main.cpp
//  leetcode find14
//
//  Created by 张超 on 2018/10/26.
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++)
        {
            iter = m.find(nums[i]);
            if (iter == m.end())
                m.emplace(nums[i], i);
            else
                if (i - iter->second > k)
                    iter->second = i;
                else
                    return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
