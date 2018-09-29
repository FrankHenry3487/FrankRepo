//
//  main.cpp
//  leetcode array6
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, idx = m + n - 1;
        while (idx1 >= 0 && idx2 >= 0) nums1[idx--] = nums1[idx1] > nums2[idx2] ? nums1[idx1--] : nums2[idx2--];
        while (idx2 >= 0) {
            nums1[idx2] = nums2[idx2];
            idx2--;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {2,5,6,0,0,0};
    vector<int> b = {1,2,3};
    Solution m;
    m.merge(a, 3, b, 3);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] <<' ';
    cout <<endl;
    return 0;
}
