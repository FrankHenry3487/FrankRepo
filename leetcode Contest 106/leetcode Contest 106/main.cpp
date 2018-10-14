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
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        while (i < A.size() && j < A.size())
        {
            if (!(A[i] & 1))
                i += 2;
            else if (A[j] & 1)
                j += 2;
            else
                swap(A[i], A[j]);
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Hello, World!\n";
    return 0;
}
