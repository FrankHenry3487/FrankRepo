//
//  main.cpp
//  leetcode 23. Merge k Sorted Lists
//
//  Created by 张超 on 2018/10/17.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        ListNode* res, *cur;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != NULL)
                pq.emplace(-lists[i]->val, lists[i]);
        if (pq.empty()) return NULL;
        res = pq.top().second;
        cur = res;
        
        while (!pq.empty())
        {
            pq.pop();
            if (cur->next != NULL)
                pq.emplace(-cur->next->val, cur->next);
            cur->next = pq.empty() ? NULL : pq.top().second;
            cur = cur->next;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(5);
    ListNode* d = new ListNode(1);
    ListNode* e = new ListNode(3);
    ListNode* f = new ListNode(4);
    ListNode* g = new ListNode(2);
    ListNode* h = new ListNode(6);
    a->next = b;
    b->next = c;
    d->next = e;
    e->next = f;
    g->next = h;
    vector<ListNode*> v = {a, d, g};
    Solution s;
    ListNode* i = s.mergeKLists(v);
    return 0;
}
