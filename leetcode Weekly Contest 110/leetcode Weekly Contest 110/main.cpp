//
//  main.cpp
//  leetcode Weekly Contest 110
//
//  Created by 张超 on 2018/11/11.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int getMinComDis(vector<int> &a, vector<int> &b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0, res = INT_MAX, alias = INT_MIN;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                if (alias != INT_MIN) {
                    res = res > (a[i] - alias) ? (a[i] - alias) : res;
                }
                alias = a[i];
                i++;
                j++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX;
        map<int, vector<int>> m;
        map<int, vector<int>>::iterator it;
        for (auto &a : points) {
            it = m.find(a[0]);
            if (it == m.end())
                m.emplace(a[0], vector<int>(1, a[1]));
            else
                it->second.push_back(a[1]);
        }
        
        for (auto &a : m) {
            if (a.second.size() >= 2) {
                for (auto &b : m) {
                    if (b.first <= a.first || b.second.size() < 2) continue;
                    int tmp = getMinComDis(a.second, b.second);
                    if (tmp != INT_MAX) tmp *= (b.first - a.first);
                    res =  tmp < res ? tmp : res;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> a = {{3,2},{0,0},{3,3},{3,4},{4,4},{2,1},{4,3},{1,0},{4,1},{0,2}};
    Solution s;
    cout << s.minAreaRect(a);
    return 0;
}
