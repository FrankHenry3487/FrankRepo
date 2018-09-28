//
//  main.cpp
//  leetcode array4
//
//  Created by 张超 on 2018/9/28.
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
    void sortColors(vector<int>& nums) {
        int b = 0, e = (int)nums.size() - 1, tmp;
        
        for (int i = 0; i <= e;)
        {
            switch(nums[i])
            {
                case 0:
                    if (i != b)
                    {
                        tmp = nums[b];
                        nums[b++] = nums[i];
                        nums[i++] = tmp;
                    }
                    else
                    {
                        b++;
                        i++;
                    }
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    while (e >= 0 && nums[e] == 2)
                    {
                        e--;
                    }
                    if (i < e)
                    {
                        tmp = nums[e];
                        nums[e--] = nums[i];
                        nums[i] = tmp;
                    }
                    break;
                default:
                    break;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution a;
    vector<int> num = {2, 0, 1};
    a.sortColors(num);
    for (int i = 0; i < num.size(); i++)
        cout << num[i];
    cout << endl;
    return 0;
}
