//
//  main.cpp
//  leetcode Contest 106
//
//  Created by 张超 on 2018/10/14.
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
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int a[300];
        map<int, int> g_id;
        set<int> s_g_id_2, s_g_id;
        
        for (int i = 0; i < 300; i++)
        {
            a[i] = i;
        }
        
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = i + 1; j < graph.size(); j++)
            {
                if (graph[i][j])
                {
                    if (a[j] > i)
                        a[j] = i;
                }
            }
        }
        
        for (int i = 0; i < graph.size(); i++)
        {
            if (a[i] == i)
                g_id.emplace(a[i], 1);
            else
                g_id.find(a[i])->second++;
        }
        
        int best = 3;
        for (int i = 0; i < initial.size(); i++)
        {
            int vurs = initial[i];
            int group = g_id.find(a[vurs])->second;
            if (group == 2)
            {
                best = 2;
                s_g_id_2.insert(group);
            }
            else
            {
                s_g_id.insert(group);
            }
        }
        
        set<int>& fin = best == 2 ? s_g_id_2 : s_g_id;
        for(int i = 0; i < graph.size(); i++)
        {
            if (fin.end() != fin.find(a[i]))
                return i;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,1,0}, b = {1,1,0}, c={0,0,1}, ini={0,1   };
    vector<vector<int>> A = {a,b,c};
    Solution s;
    cout << s.threeSumMulti(a, 0);
    return 0;
}
