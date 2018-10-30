//
//  main.cpp
//  leetcode 878. Nth Magical Number
//
//  Created by 张超 on 2018/10/30.
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

const int MOD = 1000000007;

struct node
{
    int mod;
    unsigned long long cnt;
    node(int a):mod(a),cnt(0){}
    node(node &n, int a);
};

node::node(node &n, int a)
{
    cnt = n.cnt + (long long)n.mod * a / MOD;
    mod = (long long)n.mod * a % MOD;
}

struct cmp {
    bool operator() (const node &a, const node &b)
    {
        if (a.cnt > b.cnt)
            return true;
        else if (a.cnt == b.cnt)
            return (a.mod > b.mod);
        else
            return false;
    }
};

class Solution {
    
public:
    int nthMagicalNumber(int N, int A, int B) {
        priority_queue<node, vector<node>, cmp> pq;
        pq.push(node(A));
        pq.push(node(B));
        for (int i = 0; i < N - 1; i++)
        {
            node tmp = pq.top();
            pq.push(node(tmp, A));
            pq.push(node(tmp, B));
            pq.pop();
        }
        node res = pq.top();
        return res.mod;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
