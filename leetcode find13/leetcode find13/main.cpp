//
//  main.cpp
//  leetcode find13
//
//  Created by 张超 on 2018/10/25.
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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<double, int> m;
        map<double, int>::iterator iter;
        double slop = 0.0;
        int res = 0, same;
        if (points.size() == 0) return 0;
        for (int i = 0; i < points.size(); i++)
        {
            m.clear();
            same = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j) continue;
                if (points[i].y - points[j].y == 0)
                {
                    slop = 9e9;
                    if (points[i].x - points[j].x == 0)
                    {
                        same++;
                        slop = 9e10;
                    }
                }
                else
                    slop = ((double)(points[i].x - points[j].x))/(points[i].y - points[j].y);
                iter = m.find(slop);
                if (iter == m.end())
                    m.emplace(slop, 1);
                else
                    iter->second++;
            }
            for (auto &a : m)
            {
                if(res < (a.second + same) && a.first != 9e10)
                    res = a.second + same;
                else if (res < same)
                    res = same;
            }
        }
        return res + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
