//
//  main.cpp
//  leetcode find4
//
//  Created by 张超 on 2018/10/10.
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = 0, n2 = 0, size1 = (int)nums1.size(), size2 = (int)nums2.size();
        vector<int> res;
        while (n1 != size1 && n2 != size2)
        {
            if (nums1[n1] == nums2[n2])
            {
                res.push_back(nums1[n1++]);
                n2++;
            }
            else if (nums1[n1] < nums2[n2])
            {
                n1++;
            }
            else
            {
                n2++;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
