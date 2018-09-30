//
//  main.cpp
//  leetcode array7
//
//  Created by 张超 on 2018/9/30.
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res = {0, (int)numbers.size() - 1};
        while(res[0] < res[1])
        {
            if ((numbers[res[0]] + numbers[res[1]]) > target)
                res[1]--;
            else if ((numbers[res[0]] + numbers[res[1]]) < target)
                res[0]++;
            else
                break;
        }
        res[0]++;
        res[1]++;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
