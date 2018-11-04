//
//  main.cpp
//  leetcode Weekly Contest 109
//
//  Created by 张超 on 2018/11/4.
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

class RecentCounter {
    set<int> s;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int res = 0;
        s.insert(t);
        set<int>::iterator a = s.lower_bound(t - 3000);
        set<int>::iterator b = s.upper_bound(t);
        while(a != b)
        {
            res++;
            a++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << "Hello, World!\n";
    return 0;
}
