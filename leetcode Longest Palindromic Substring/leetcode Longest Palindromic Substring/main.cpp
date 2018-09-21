//
//  main.cpp
//  leetcode Longest Palindromic Substring
//
//  Created by 张超 on 2018/9/20.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void palindromeOfIndex1(string& s, int idx, int& longest, string& output)
    {
        int idx1 = idx - 1;
        int idx2 = idx + 1;
        int length = 1;
        
        while (idx1 >= 0 && idx2 < s.size() && s[idx1] == s[idx2])
        {
            length += 2;
            idx1 -= 1;
            idx2 += 1;
        }
        if (length > longest)
        {
            longest = length;
            output = string(s, idx1 + 1, length);
        }
    }
    
    void palindromeOfIndex2(string& s, int idx, int& longest, string& output)
    {
        int idx1 = idx;
        int idx2 = idx + 1;
        int length = 0;
        
        while (idx1 >= 0 && idx2 < s.size() && s[idx1] == s[idx2])
        {
            length += 2;
            idx1 -= 1;
            idx2 += 1;
        }
        if (length > longest)
        {
            longest = length;
            output = string(s, idx1 + 1, length);
        }
    }
    
    string longestPalindrome(string s) {
        int longest = 0;
        string longestStr = "";
        for (int i = 0; i < s.size(); i++)
        {
            palindromeOfIndex1(s, i, longest, longestStr);
            palindromeOfIndex2(s, i, longest, longestStr);
        }
        return longestStr;
    }
};

int main(int argc, const char * argv[]) {
    string s("cbbd");
    Solution a;
    cout << a.longestPalindrome(s);
    return 0;
}
