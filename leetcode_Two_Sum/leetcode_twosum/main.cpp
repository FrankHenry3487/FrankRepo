//
//  main.cpp
//  leetcode_twosum
//
//  Created by 张超 on 2018/9/16.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //o(x^2)的时间复杂度，不是最优算法
    vector<int> twoSum(vector<int>& nums, int target) {
        int x,y;
        vector<int> out;
        for (x = 0; x < nums.size(); x++)
        {
            for (y = (x + 1); y < nums.size(); y++)
            {
                if ((nums[x] + nums[y]) == target)
                {
                    out.push_back(x);
                    out.push_back(y);
                    return out;
                }
            }
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {
    int in[] = {2,4,6,3,5};
    int target = 11;
    vector<int> input(in, in + sizeof(in)), output;
    Solution a;
    output = a.twoSum(input, target);
    cout << output[0] <<" " <<output[1] <<endl;
    return 0;
}
