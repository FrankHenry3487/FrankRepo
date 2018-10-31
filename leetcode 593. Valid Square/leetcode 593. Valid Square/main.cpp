//
//  main.cpp
//  leetcode 593. Valid Square
//
//  Created by 张超 on 2018/10/31.
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
    map<int, int> m;
    void add_distance(vector<int>& p1, vector<int>& p2)
    {
        map<int,int>::iterator iter;
        int res = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        iter = m.find(res);
        if (m.end() != iter)
            iter->second++;
        else
            m.emplace(res, 1);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        add_distance(p1, p2);
        add_distance(p1, p3);
        add_distance(p1, p4);
        add_distance(p2, p3);
        add_distance(p2, p4);
        add_distance(p3, p4);
        if (m.size() != 2) return false;
        int one = -1;
        for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        {
            if (one == -1)
            {
                if (iter->second != 4)
                    return false;
                one = iter->first;
            }
            else
            {
                if (iter->second != 2)
                    return false;
                if (one * 2 != iter->first)
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
