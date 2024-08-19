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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == NULL) {
      return false;
    }
    return recurse(root, targetSum, 0);
  }


  bool recurse(TreeNode *node, int targetSum, int sum) {
    if (node == NULL) {
      return false;
    }
    if (node->left == NULL && node->right == NULL) {
      return sum + node->val == targetSum;
    }

    return recurse(node->left, targetSum, sum + node->val) || recurse(node->right, targetSum, sum + node->val);
  }
};










  return 0;
}