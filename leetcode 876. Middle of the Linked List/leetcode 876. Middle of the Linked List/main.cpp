//
//  main.cpp
//  leetcode 876. Middle of the Linked List
//
//  Created by 张超 on 2018/10/23.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
    class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            vector<ListNode*> v;
            int node_cnt = 0;
            ListNode* cur = head;
            while (cur != NULL)
            {
                node_cnt++;
                v.push_back(cur);
                cur = cur->next;
            }
            return v[node_cnt/2];
        }
    };

int main(int argc, const char * argv[]) {
    ListNode a(1), b(2), c(3), d(4), e(5), h(0);
    Solution s;
    h.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode* p = s.middleNode(&h);
    return 0;
}
