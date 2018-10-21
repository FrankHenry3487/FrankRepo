//
//  main.cpp
//  Weekly Contest 107
//
//  Created by 张超 on 2018/10/21.
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
    int n;
    vector<int> infected;
    int sum(vector<int> &v) {
        int rt = 0;
        for (int x : v) {
            rt += x;
        }
        return rt;
    }
    void floodfill(int cur, const vector<vector<int>> &graph, int exc) {
        if (infected[cur]) {
            return;
        }
        //cout << "#infect: " << cur << endl;
        infected[cur] = 1;
        for (int nxt = 0; nxt<n ; nxt++) {
            if (nxt==cur || graph[cur][nxt]==0 || nxt==exc) {
                continue;
            }
            floodfill(nxt, graph, exc);
        }
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n = (int)graph.size();
        int minNode = -1;
        int minInfected = n+1;
        for (int exc : initial) {
            infected.assign(n, 0);
            //cout << "#try: " << exc << endl;
            for (int node : initial) {
                if (node == exc) {
                    continue;
                }
                floodfill(node, graph, exc);
            }
            int res = sum(infected);
            //cout << "#result: " << res << endl;
            if (res<minInfected) {
                minInfected = res;
                minNode = exc;
            } else if (res==minInfected) {
                minNode = min(minNode, exc);
            }
        }
        return minNode;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> a = {1,1,0,1,1,0,1,1,0};
    s.threeEqualParts(a);
    return 0;
}
