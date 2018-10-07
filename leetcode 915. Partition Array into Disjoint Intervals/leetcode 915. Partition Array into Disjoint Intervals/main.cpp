//
//  main.cpp
//  leetcode 915. Partition Array into Disjoint Intervals
//
//  Created by 张超 on 2018/10/4.
//  Copyright © 2018年 张超. All rights reserved.
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
private:
    
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> min, max;
        const int size = (int)A.size();
        min.resize(size);
        max.resize(size);
        max[0] = A[0];
        min[size - 1] = A[size - 1];
        for (int i = 1; i < size; i++)
        {
            max[i] = max[i - 1] > A[i] ? max[i - 1] : A[i];
            min[size - 1 - i] = min[size - i] > A[size - 1 - i] ? A[size - 1 - i] : min[size - i];
        }
        
        for (int i = 0; i < max.size() - 1; i++)
        {
            if (max[i] <= min[i + 1])
            {
                return i + 1;
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {1,1,1,0,6,12};
    Solution S;
    cout << S.partitionDisjoint(a);
    return 0;
}
