//
//  main.cpp
//  leetcode 12. Integer to Roman
//
//  Created by 张超 on 2018/10/15.
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
    string intToRoman(int num) {
        int n_th = num / 1000;
        num %= 1000;
        string res;
        res.append(n_th, 'M');
        
        int n_th2 = num / 100;
        num %= 100;
        if (n_th2 == 9)
            res.append("CM");
        else if (n_th2 == 4)
            res.append("CD");
        else {
            if (n_th2 > 4)
            {
                res.append(1, 'D');
            }
            res.append(n_th2 % 5, 'C');
        }
        
        int n_th3 = num / 10;
        num %= 10;
        if (n_th3 == 9)
            res.append("XC");
        else if (n_th3 == 4)
            res.append("XL");
        else {
            if (n_th3 > 4)
            {
                res.append(1, 'L');
            }
            res.append(n_th3 % 5, 'X');
        }
        
        if (num == 9)
            res.append("IX");
        else if (num == 4)
            res.append("IV");
        else{
            if (num > 4)
                res.append(1, 'V');
            res.append(num % 5, 'I');
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
