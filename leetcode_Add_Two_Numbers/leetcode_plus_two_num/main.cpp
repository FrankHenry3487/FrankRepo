//
//  main.cpp
//  leetcode_plus_two_num
//
//  Created by 张超 on 2018/9/16.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    //ListNode(int x, ListNode* l): val(x), next(l) {}
};

class Solution {
public:
    unsigned long List2Num(ListNode *l)
    {
        ListNode* cur = l;
        unsigned long power = 1;
        unsigned long return_value = 0;
        while(cur->next != NULL)
        {
            return_value += (unsigned long)cur->val * power;
            power *= 10;
            cur = cur->next;
        }
        
        return_value += (unsigned long)cur->val * power;
        return return_value;
    }
    
    ListNode* Num2List(unsigned long num)
    {
        ListNode* headNode = NULL, *tailNode = NULL;
        
        headNode = new ListNode(num % 10);
        tailNode = headNode;
        
        while (num / 10 != 0)
        {
            num /= 10;
            tailNode->next = new ListNode(num % 10);
            tailNode = tailNode->next;
        }
        return headNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1, *cur2 = l2, *cur3 = NULL, *out = NULL;
        bool isCarry = false;
        int node_sum = 0, tmp1 = 0, tmp2 = 0;
        while (cur1 != NULL || cur2 != NULL || isCarry)
        {
            if (cur1) tmp1 = cur1->val;
            else tmp1 = 0;
            if (cur2) tmp2 = cur2->val;
            else tmp2 = 0;
            
            if (isCarry)
            {
                node_sum = tmp1 + tmp2 + 1;
            }
            else
            {
                node_sum = tmp1 + tmp2;
            }
            if (node_sum > 9) isCarry = true;
            else isCarry = false;
            
            if (cur3)
            {
                cur3->next = new ListNode(node_sum % 10);
                cur3 = cur3->next;
            }
            else
            {
                cur3 = new ListNode(node_sum % 10);
                out = cur3;
            }
            
            if (cur1) cur1 = cur1->next;
            if (cur2) cur2 = cur2->next;
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1, *node1_cp;
    Solution a;
    node1 = a.Num2List(999);
    node1_cp = node1;
    while (node1) {
        std::cout << node1->val <<std::endl;
        node1 = node1->next;
    }
    std::cout << std::endl <<a.List2Num(node1_cp);
    
    ListNode* node2 = a.Num2List(99999);
    std::cout << std::endl <<a.List2Num(node2);
    
    std::cout << std::endl <<a.List2Num(a.addTwoNumbers(node1_cp, node2));
    return 0;
}
