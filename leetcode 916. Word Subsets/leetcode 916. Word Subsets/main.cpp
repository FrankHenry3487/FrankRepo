//
//  main.cpp
//  leetcode 916. Word Subsets
//
//  Created by 张超 on 2018/10/3.
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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int patern[26] = {0};
        int word[26] = {0};
        vector<string> res;
        
        for (int i = 0; i < B.size(); i++)
        {
            memset(word, 0, 26 * sizeof(int));
            for (int j = 0; j < B[i].size(); j++)
                word[B[i][j] - 'a']++;
            for (int j = 0; j < 26; j++)
                if (patern[j] < word[j]) patern[j] = word[j];
        }
        
        int is_subset = true;
        for (int i = 0; i < A.size(); i++)
        {
            is_subset = true;
            memset(word, 0, 26 * sizeof(int));
            for (int j = 0; j < A[i].size(); j++)
                word[A[i][j] - 'a']++;
            
            for (int j = 0; j < 26; j++)
            {
                if (patern[j] > word[j])
                {
                    is_subset = false;
                    break;
                }
            }
            if (is_subset) res.push_back(A[i]);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> A = {"amazon","apple","facebook","google","leetcode"};
    vector<string> B = {"ec","oc","ceo"};
    Solution S;
    vector<string> C = S.wordSubsets(A, B);
    for (int i = 0; i < C.size(); i++)
        cout << C[i] <<endl;
    return 0;
}

