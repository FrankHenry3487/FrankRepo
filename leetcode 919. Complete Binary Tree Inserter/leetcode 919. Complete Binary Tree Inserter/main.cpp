//
//  main.cpp
//  leetcode 919. Complete Binary Tree Inserter
//
//  Created by 张超 on 2018/10/10.
//  Copyright © 2018年 张超. All rights reserved.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {
private:
    TreeNode* m_root;
    int m_num;
    
    void nodeCnt(TreeNode* node)
    {
        if (node) {
            m_num++;
            nodeCnt(node->left);
            nodeCnt(node->right);
        }
    }
    
public:
    CBTInserter(TreeNode* root) {
        m_root = root;
        m_num = 0;
        nodeCnt(root);
    }
    
    int insert(int v) {
        TreeNode* newNode = new TreeNode(v);
        if (newNode == NULL)
            return NULL;
        m_num++;
        
        int n = 1;
        while (n <= m_num)
            n = n << 1;
        n = n >> 1; //表征所在行的开头
        
        int line_cnt = m_num - n;
        TreeNode* cur = m_root;
        
        n = n >> 1; //表征对应层左右两边的个数(比如第4层(开头为2^(4 - 1)号，即8号)，次层为8 - 15，左右半区各2 ^ (4 - 2 )个，即4个)
        while(n >> 1) //n != 1
        {
            //节点位于右半区
            if (line_cnt / n == 1)
            {
                cur = cur->right;
                line_cnt -= n; //从右半区下钻，起点变为中间(或者说忽略左半区)
            }
            else
            {
                cur = cur->left;
            }
            
            n = n >> 1; //下钻后，下一层，左右半区缩小一半
        }
        
        if (line_cnt)
            cur->right = newNode;
        else
            cur->left = newNode;
        
        return cur->val;
    }
    
    TreeNode* get_root() {
        return m_root;
    }
};


int main(int argc, const char * argv[]) {
    TreeNode a(1);
    CBTInserter incerter(&a);
    incerter.insert(2);
    incerter.insert(3);
    incerter.insert(4);
    incerter.insert(5);
    incerter.insert(6);
    CBTInserter inb(incerter.get_root());
    inb.insert(7);
    return 0;
}
