//
//  main.cpp
//  leetcode 97. Interleaving String
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
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()){return false;}
        vector<vector<int> > dp(s1.length() + 1, vector<int>(s2.length() + 1));
        dp[0][0] = 1;
        for(int i = 0; i < s1.length() + 1; i++){
            for(int j = 0; j < s2.length() + 1; j++){
                if(i > 0 && dp[i-1][j] == 1 && s1[i-1] == s3[i+j-1]){
                    dp[i][j] = 1;
                }
                if(j > 0 && dp[i][j-1] == 1 && s2[j-1] == s3[i+j-1]){
                    dp[i][j] = 1;
                }
            }
        }
        return (dp[s1.length()][s2.length()] == 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
    s2 = "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
    s3 = "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb";
    Solution s;
    cout << s.isInterleave(s1, s2, s3);
    return 0;
}
