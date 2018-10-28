//
//  main.cpp
//  leetcode weekly contest 108
//
//  Created by 张超 on 2018/10/28.
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
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        bool is_plus;
        string tmp;
        for (auto& email : emails)
        {
            tmp.clear();
            is_plus = false;
            for (int i = 0; i < email.size(); i++)
            {
                switch(email[i])
                {
                    case '.':
                        break;
                    case '+':
                        is_plus = true;
                        break;
                    case '@':
                        tmp += email.substr(i + 1);
                        break;
                    default:
                        if (is_plus)
                            break;
                        else
                            tmp += email[i];
                        break;
                }
            }
            if (s.end() == s.find(tmp))
                s.insert(tmp);
        }
        return (int)s.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
