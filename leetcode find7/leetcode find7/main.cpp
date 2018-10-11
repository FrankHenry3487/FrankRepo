//
//  main.cpp
//  leetcode find7
//
//  Created by 张超 on 2018/10/11.
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
public:
    string frequencySort(string s) {
        int cnt[256] = {0}, size = (int)s.size(), max = 0, cur = 0;
        for (int i = 0; i < size; i++) {
            cnt[s[i]]++;
            max = max > cnt[s[i]] ? max : cnt[s[i]];
        }
        for (; max > 0; max--)
        {
            for (int i = 0; i < 256; i++)
            {
                if (cnt[i] == max)
                {
                    for (int j = 0; j < max; j++)
                        s[cur++] = (char)i;
                }
            }
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
