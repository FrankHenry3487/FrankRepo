//
//  main.cpp
//  leetcode array10
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
    int maxArea(vector<int>& height) {
        int m = (int)height.size();
        int max = 0;
        int tmp_h = 0;
        int h;
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                h = height[i] > height[j] ? height[j] : height[i];
                tmp_h = h * (j - i);
                max = max > tmp_h ? max : tmp_h;
            }
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {};
    cout << "Hello, World!\n";
    return 0;
}
