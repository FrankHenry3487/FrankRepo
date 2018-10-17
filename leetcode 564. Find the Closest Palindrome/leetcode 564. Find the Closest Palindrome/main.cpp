//
//  main.cpp
//  leetcode 564. Find the Closest Palindrome
//
//  Created by 张超 on 2018/10/17.
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
    string nearestPalindromic(string n) {
        bool isPaliNum = true;
        char last = 0;
        if (n[0] == '1' && n.size() > 1)
        {
            int i = 1;
            for (; i < n.size(); i++)
            {
                if (n[i] != '0')
                    break;
            }
            if (i == n.size() || (i == n.size() - 1 && n[i] == '1'))
            {
                string res(n.size() - 1, '9');
                return res;
            }
        }
        else if (n[0] == '9' && n.size() > 1)
        {
            int j = 1;
            for (; j < n.size(); j++)
            {
                if (n[j] != '9')
                    break;
            }
            if (j == n.size())
            {
                string res(n.size() + 1, '0');
                res[0] = '1';
                res[n.size()] = '1';
                return res;
            }
        }
        int b = 0, e = (int)n.size() - 1;
        while (b < e - 1)
        {
            last = n[e];
            if (n[b] != n[e])
            {
                n[e] = n[b];
                isPaliNum = false;
            }
            e--;
            b++;
        }
        if (isPaliNum)
        {
            if (b != e)
            {
                if (n[b] > n[e])
                {
                    n[b] = (n[b] - n[e]) >= (10 + n[e] - n[b] + 1) ? (n[b] - 1) : n[b];
                    n[e] = n[b];
                    return n;
                }
                else if (n[b] < n[e])
                {
                    n[b] = (n[e] - n[b]) > (10 + n[b] + 1 - n[e]) ? (n[b] + 1) : n[b];
                    n[e] = n[b];
                    return n;
                }
            }
            
            if (n[e] == '0')
            {
                n[b] = '1';
                n[e] = n[b];
            }
            else
            {
                n[e]--;
                n[b] = n[e];
            }
        }
        else if (b != e)
        {
            if (n[b] > n[e])
            {
                n[b] = (n[b] - n[e]) >= (10 + n[e] - n[b] + 1) ? (n[b] - 1) : n[b];
                n[e] = n[b];
            }
            else if (n[b] < n[e])
            {
                n[b] = (n[e] - n[b]) > (10 + n[b] + 1 - n[e]) ? (n[b] + 1) : n[b];
                n[e] = n[b];
            }
        }
        else
        {
            if (last < n[e - 1])
            {
                if (n[e] != '0')
                    n[e] = (n[e - 1] - last) >= 5 ? n[e] - 1 : n[e];
            }
            else if (last > n[e - 1])
            {
                if (n[e] != '9')
                    n[e] = (last - n[e - 1]) > 5 ? n[e] + 1 : n[e];
            }
        }
        return n;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.nearestPalindromic("1837722381");
    return 0;
}
