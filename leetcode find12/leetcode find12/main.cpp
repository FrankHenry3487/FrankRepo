//
//  main.cpp
//  leetcode find12
//
//  Created by 张超 on 2018/10/24.
//  Copyright © 2018 张超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
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
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> m;
        int res = 0;
        unordered_map<int, int>::iterator iter;
        if (points.size() < 3) return 0;
        for (int i = 0; i < points.size(); i ++)
        {
            m.clear();
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j) continue;
                int dis = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                iter = m.find(dis);
                if (m.end() != iter)
                    iter->second++;
                else
                    m.emplace(dis, 1);
            }
            for (auto &a : m)
            {
                if (a.second > 1)
                    res += a.second * (a.second - 1);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int, int>> a;
    a.push_back(make_pair(0, 0));
    a.push_back(make_pair(<#_T1 &&__t1#>, <#_T2 &&__t2#>))
    cout << "Hello, World!\n";
    return 0;
}
