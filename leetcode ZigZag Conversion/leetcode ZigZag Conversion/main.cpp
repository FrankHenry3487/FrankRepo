//
//  main.cpp
//  leetcode ZigZag Conversion
//
//  Created by 张超 on 2018/9/21.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

static const auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string convert(string s, int numRows) {
        unsigned long length = s.length();
        string strOut(s);
        int idx = 0;
        if (numRows == 1) return strOut;
        
        for (int row = 0; row < numRows; row++)
        {
            int n = 0;
            while ((2 * (numRows - 1) * n + row) < length)
            {
                //这种场景没有中间元素
                if (row == 0 || row == (numRows - 1))
                {
                    strOut[idx++] = s[2 * (numRows - 1) * n + row];
                }
                else
                {
                    strOut[idx++] = s[2 * (numRows - 1) * n + row];
                    if (2 * (numRows - 1) * n + row + 2 * (numRows - 1 - row) >= length)
                    {
                        break;
                    }
                    strOut[idx++] = s[2 * (numRows - 1) * n + row + 2 * (numRows - 1 - row)];
                }
                n++;
            }
        }
        return strOut;
    }
};

int main(int argc, const char * argv[]) {
    string s("PAYPALISHIRING");
    Solution a;
    cout << a.convert(s, 4);
    return 0;
}
