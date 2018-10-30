//
//  main.cpp
//  leetcode 896. Monotonic Array
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

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 3) return true;
        int flag = 0;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] > A[i - 1])
            {
                if (flag == 1)
                    return false;
                else if (flag == 0)
                    flag = 2;
            }
            if (A[i] < A[i - 1])
            {
                if (flag == 2)
                    return false;
                else if (flag == 0)
                    flag = 1;
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
