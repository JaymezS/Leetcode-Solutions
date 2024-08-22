#include <bits/stdc++.h>

using namespace std;

int main(){





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  TreeNode *x;
  TreeNode *y;
  TreeNode *lNode = NULL;
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    x = p;
    y = q;
    hasChild(root, false, false);
    return lNode;
  }

  pair<bool, bool> hasChild(TreeNode * root, bool hasX, bool hasY) {
    if (root ->left == NULL && root->right == NULL) {
      return {root == x, root == y};
    }

    pair<bool, bool> has = {root == x, root == y};

    if (root->left) {
      pair<bool, bool> l = hasChild(root->left, hasX, hasY);
      has.first = has.first || l.first;
      has.second = has.second || l.second;
    }
    if (root->right) {
      pair<bool, bool> r = hasChild(root->right, hasX, hasY);
      has.first = has.first || r.first;
      has.second = has.second || r.second;
    }
    
    if (has.first == true && has.second == true) {
      if (lNode == NULL) {
        lNode = root;
      }
    }
    return has;
  }
};










  return 0;
}