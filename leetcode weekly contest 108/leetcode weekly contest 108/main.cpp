//
//  main.cpp
//  leetcode weekly contest 108
//
//  Created by 张超 on 2018/10/28.
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
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> aidx;
        for (int i = 0; i < A.size(); i++)
            if (A[i] == 1)
                aidx.push_back(i);
        if (S > 0)
        {
            int f = 0, e = S - 1, res = 0, cnt1 = 0, cnt2 = 0;
            while (e < aidx.size())
            {
                if (f != 0)
                    cnt1 = aidx[f] - aidx[f - 1];
                else
                    cnt1 = aidx[0] + 1;
                if (e != aidx.size() - 1)
                    cnt2 = aidx[e + 1] - aidx[e];
                else
                    cnt2 = (int)A.size() - aidx[e];
                res += cnt1 * cnt2;
                f++;
                e++;
            }
            return res;
        }
        else
        {
            int res = 0, zn;
            for (int i = 1; i < aidx.size(); i++)
            {
                zn = aidx[i] - aidx[i - 1] - 1;
                res += (1 + zn) * zn / 2;
            }
            if (aidx.size() > 0)
            {
                zn = aidx[0];
                res += (1 + zn) * zn / 2;
                zn = (int)A.size() - aidx[aidx.size() - 1] - 1;
                res += (1 + zn) * zn / 2;
            }
            else
            {
                return ((int)A.size() + 1) * (int)A.size() / 2;
            }
            return res;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0};
    Solution s;
    
    cout << s.numSubarraysWithSum(a, 3);
    return 0;
}
