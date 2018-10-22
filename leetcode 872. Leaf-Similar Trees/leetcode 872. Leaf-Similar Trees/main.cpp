//
//  main.cpp
//  leetcode 872. Leaf-Similar Trees
//
//  Created by 张超 on 2018/10/22.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> leaf1, leaf2;
    
    void visit(TreeNode* n, vector<int>& leaf)
    {
        if (n->left == NULL && n->right == NULL)
            leaf.push_back(n->val);
        else
        {
            if (n->left != NULL)
                visit(n->left, leaf);
            if (n->right != NULL)
                visit(n->right, leaf);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        visit(root1, leaf1);
        visit(root2, leaf2);
        if (leaf1.size() != leaf2.size()) return false;
        for (int i = 0; i < leaf1.size(); i++)
            if (leaf1[i] != leaf2[i]) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode a1(1), a2(2);
    cout << s.leafSimilar(&a1, &a2);
    return 0;
}
