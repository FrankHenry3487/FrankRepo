//
//  main.cpp
//  leetcode 917. Reverse Only Letters
//
//  Created by 张超 on 2018/10/8.
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
    bool isLetter(char x)
    {
        return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
    }
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = (int)S.size() - 1;
        char tmp;
        while (i < j)
        {
            if (!isLetter(S[i]))
                i++;
            else if (!isLetter(S[j]))
                j--;
            else
            {
                tmp = S[i];
                S[i++] = S[j];
                S[j--] = tmp;
            }
        }
        return S;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
