#include <bits/stdc++.h>

using namespace std;

int main(){





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    return recurse(root, root);
  }

  bool recurse(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {
      return true;
    } if (left != NULL && right || NULL) {
      if (left->val == right->val) {
        return recurse(left->left, right->right) && recurse(left->right, right->left);
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
};










  return 0;
}