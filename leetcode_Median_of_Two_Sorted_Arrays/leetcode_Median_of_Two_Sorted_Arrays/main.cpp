//
//  main.cpp
//  leetcode_Median_of_Two_Sorted_Arrays
//
//  Created by 张超 on 2018/9/19.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double min(int a, int b)
    {
        if (a > b)
            return (double)b;
        return (double)a;
    }
    
    double max(int a, int b)
    {
        if (a > b)
            return (double)a;
        return (double)b;
    }
    
    double medium(int a, int b, int c)
    {
        if (a >= b && b >= c)
            return (double)b;
        if (c >= b && b >= a)
            return (double)b;
        if (b >= a && a >= c)
            return (double)a;
        if (c >= a && a >= b)
            return (double)a;
        return (double)c;
    }
    
    double medium(int a, int b, int c, int d)
    {
        int min = a, max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        if (d > max) max = d;
        if (b < min) min = b;
        if (c < min) min = c;
        if (d < min) min = d;
        return (((double)(a + b + c + d - min - max)) / 2);
    }
    
    double findMedian(vector<int>& little, vector<int>& big, unsigned long range_low,
                      unsigned long range_high, bool director) //director: true for left, false for right
    {
        unsigned long total_size = little.size() + big.size();
        unsigned long this_index_little = (range_low + range_high) / 2;
        //if search to right side's end, actually goto end
        if ((1 == (range_high - range_low)) && false == director && little.size() != 0)
            this_index_little++;

        //if index in one array is fixed, the index in another array is fixed too.
        unsigned long this_index_big = total_size / 2 - this_index_little;
        
        //迭代出口1，小数组已经查找到边缘，则中位数一定在长数组中两个相邻
        if (0 == this_index_little || little.size() == this_index_little)
        {
            if (total_size % 2 == 1)
            {
                if (little.size() == 0)
                    return (double)big[this_index_big];
                
                if (this_index_big)
                    return medium(little[this_index_little], big[this_index_big], big[this_index_big - 1]);
                return max(little[this_index_little - 1], big[this_index_big]);
            }
            else
            {
                if (little.size() == 0)
                {
                    return (double)(big[this_index_big] + big[this_index_big - 1]) / 2;
                }
                if (little.size() != big.size())
                {
                    if (little.size() == 1)
                        return medium(little[this_index_little], big[this_index_big], big[this_index_big - 1], big[this_index_big - 2]);
                    if (this_index_little)
                        return (max(big[this_index_big - 1], little[this_index_little - 1]) + (double)big[this_index_big]) / 2;
                    return (min(big[this_index_big], little[this_index_little]) + (double)big[this_index_big - 1]) / 2;
                }
                else
                {
                    if (this_index_big)
                        return ((double)big[this_index_big - 1] + (double)little[this_index_little]) / 2;
                    return ((double)big[this_index_big] + (double)little[this_index_little - 1]) / 2;
                }
            }
        }

        //迭代出口2，4个数字实现了大小交叉
        if (little[this_index_little] >= big[this_index_big - 1] && little[this_index_little - 1] <= big[this_index_big])
        {
            if (total_size % 2 == 1)
            {
                return min(little[this_index_little], big[this_index_big]);
            }
            else
            {
                return (min(little[this_index_little], big[this_index_big]) + max(little[this_index_little - 1], big[this_index_big - 1])) / 2;
            }
        }
        
        //没有实现大小交叉继续迭代
        if (little[this_index_little - 1] > big[this_index_big])
        {
            return findMedian(little, big, range_low, this_index_little, true);
        }
        else
        {
            return findMedian(little, big, this_index_little, range_high, false);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() >= nums2.size())
        {
            return findMedian(nums2, nums1, 0, nums2.size(), true);
        }
        else
        {
            return findMedian(nums1, nums2, 0, nums1.size(), true);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {4, 5};
    vector<int> nums2 = {1, 2, 3, 6};
    Solution a;
    cout << a.findMedianSortedArrays(nums1, nums2);
    return 0;
}
