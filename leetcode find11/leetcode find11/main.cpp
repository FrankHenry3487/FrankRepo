//
//  main.cpp
//  leetcode find11
//
//  Created by 张超 on 2018/10/19.
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<int> tmp;
        vector<vector<int>> tplt;
        for (int i = 0; i < strs.size(); i++)
        {
            tmp.clear();
            tmp.resize(26, 0);
            for (int j = 0; j < strs[i].size(); j++)
                tmp[strs[i][j] - 'a']++;
            bool is_found = false;
            for (int j = 0; j < tplt.size(); j++)
            {
                int k = 0;
                for (; k < 26; k++)
                {
                    if (tplt[j][k] != tmp[k])
                        break;
                }
                if (k == 26)
                {
                    is_found = true;
                    res[j].push_back(strs[i]);
                    break;
                }
            }
            if (!is_found)
            {
                vector<string> insert = {strs[i]};
                tplt.push_back(tmp);
                res.push_back(insert);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    s.groupAnagrams(a);
    return 0;
}
