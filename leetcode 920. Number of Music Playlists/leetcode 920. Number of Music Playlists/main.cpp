//
//  main.cpp
//  leetcode 920. Number of Music Playlists
//
//  Created by 张超 on 2018/10/7.
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
    const int BIG_NUM = 1000000007;
    int allPosibility(int N, int L, int K)
    {
        int res = 1;
        for (int i = 0; i < L; i++)
        {
            if (i < K)
            {
                res *= (N - i);
            }
            else
            {
                res *= (N - K);
            }
            
            if (res > BIG_NUM)
            {
                res %= BIG_NUM;
            }
        }
        return res;
    }
    
    int combine(int N, int C)
    {
        long long dividend = 1, divisor = 1;
        for (int i = 0 ; i < C; i++)
        {
            dividend *= N - i;
            divisor *= i + 1;
        }
        return (int)(dividend / divisor);
    }
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<int> cnt(N + 1, 0);
        int res = 0;
        for (int j = K + 1; j < N + 1; j++)
        {
            res = allPosibility(j, L, K);
            res *= combine(N, j);
            if (res >= cnt[j - 1])
            {
                cnt[j] = res - cnt[j - 1];
            }
            else
            {
                cnt[j] = res + BIG_NUM - cnt[j - 1];
            }
        }
        
        return cnt[N];
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    cout << S.numMusicPlaylists(3, 3, 0);
    return 0;
}
