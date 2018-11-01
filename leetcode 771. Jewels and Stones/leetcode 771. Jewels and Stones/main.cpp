//
//  main.cpp
//  leetcode 771. Jewels and Stones
//
//  Created by 张超 on 2018/11/1.
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
    int numJewelsInStones(string J, string S) {
        sort(S.begin(), S.end());
        sort(J.begin(), J.end());
        int ij = 0, is = 0, res = 0;
        while(is < S.size() && ij < J.size())
        {
            if (J[ij] == S[is])
            {
                res++;
                is++;
            }
            else if (J[ij] < S[is])
                ij++;
            else
                is++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
