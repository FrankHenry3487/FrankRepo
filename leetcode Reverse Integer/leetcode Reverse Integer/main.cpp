//
//  main.cpp
//  leetcode Reverse Integer
//
//  Created by 张超 on 2018/9/22.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int reverse(int x) {
        long long room = 0;
        bool neg = false;
        
        if (x == -2147483648)
            return 0;
        
        if (x < 0)
        {
            neg = true;
            x = -x;
        }
        
        for (int i = 0; i < 10; i++)
        {
            if (x)
            {
                room *= 10;
                room += x % 10;
                x /= 10;
            }
            else
                break;
        }
        
        if (room <= 2147483648 && neg)
            return (int)(-room);
        else if (room < 2147483648 && !neg)
            return (int)room;
        else
            return 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution a;
    std::cout << a.reverse(2147483647);
    return 0;
}
