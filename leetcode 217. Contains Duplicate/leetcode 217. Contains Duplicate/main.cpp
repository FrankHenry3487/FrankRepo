//
//  main.cpp
//  leetcode 217. Contains Duplicate
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
#include <set>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        set<int> s;
        map<int, int>::iterator iter;
        set<int>::iterator it_s;
        int size = (int)deck.size();
        for (int i = 0; i < size; i++)
        {
            iter = m.find(deck[i]);
            if (m.end() == iter)
                m.insert(make_pair(deck[i], 1));
            else
                iter->second++;
        }
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            (void)s.insert(iter->second);
        }
        int res = *(s.begin());
        while (res > 1)
        {
            for (it_s = s.begin(); it_s != s.end(); it_s++)
            {
                if (*it_s % res != 0)
                    break;
            }
            if (it_s == s.end())
            {
                return true;
            }
            res--;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {1,1,1,2,2,2,3,3,3,4,4,4,4,4,4};
    cout << s.hasGroupsSizeX(v);
    return 0;
}
