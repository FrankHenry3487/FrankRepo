//
//  main.cpp
//  leetcode_Longest_Substring_Without_Repeating_Characters
//
//  Created by 张超 on 2018/9/20.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> current_char_map;
        map<char, int>::iterator iter;
        int max_substr_len = 0;
        int start_index = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            iter = current_char_map.find(s[i]);
            if (current_char_map.end() == iter)
            {
                //如果字符还未重复，则加入map表示子串增长
                current_char_map.insert(pair<char, int>(s[i], i));
            }
            else
            {
                //如果是到现在发现的最长子串，记录下来
                if (i - start_index > max_substr_len) {
                    max_substr_len = i - start_index;
                }
                //清空map，从上个重复字符开始继续扫描
                start_index = iter->second + 1;
                i = iter->second;
                current_char_map.clear();
            }
        }
        
        if (s.length() - start_index > max_substr_len) {
            max_substr_len = (int)s.length() - start_index;
        }
        
        return max_substr_len;
    }
};

int main(int argc, const char * argv[]) {
    string s("pwwkew");
    Solution a;
    cout << a.lengthOfLongestSubstring(s);
    return 0;
}
