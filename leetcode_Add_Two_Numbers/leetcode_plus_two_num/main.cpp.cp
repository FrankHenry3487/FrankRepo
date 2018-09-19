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
        return (Num2List(List2Num(l1) + List2Num(l2)));
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1, *node1_cp;
    Solution a;
    node1 = a.Num2List(1000000001);
    node1_cp = node1;
    while (node1) {
        std::cout << node1->val <<std::endl;
        node1 = node1->next;
    }
    std::cout << std::endl <<a.List2Num(node1_cp);
    
    ListNode* node2 = a.Num2List(6543210);
    std::cout << std::endl <<a.List2Num(node2);
    
    std::cout << std::endl <<a.List2Num(a.addTwoNumbers(node1_cp, node2));
    return 0;
}
