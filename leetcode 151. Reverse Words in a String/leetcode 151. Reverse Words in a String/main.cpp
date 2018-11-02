//
//  main.cpp
//  leetcode 151. Reverse Words in a String
//
//  Created by 张超 on 2018/11/2.
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
    void split( const string &str, const string &delimiters, vector<string> &elems) {
        string::size_type pos, prev = 0;
        while ( ( pos = str.find_first_of(delimiters, prev) ) != string::npos ) {
            if ( pos > prev ) {
                elems.emplace_back( str, prev, pos - prev );
            }
            prev = pos + 1;
        }
        if ( prev < str.size() ) elems.emplace_back( str, prev, str.size() - prev );
    }
    
    void reverseWords(string &s) {
        vector<string> res ;
        split(s, " ", res);
        if (res.size() == 1)
        {
            s = res[0];
            return;
        }
        else if (res.size() == 0)
        {
            s = "";
            return;
        }
        int i = (int)res.size() - 2;
        s = res[res.size() - 1];
        while(~i)
        {
            s += " ";
            s += res[i--];
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string ss = "Could the input string contain leading or trailing spaces";
    s.reverseWords(ss);
    cout << ss;
    return 0;
}
