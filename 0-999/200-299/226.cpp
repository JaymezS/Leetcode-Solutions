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
  TreeNode* invertTree(TreeNode* root) {
    inv(root);
    return root;
  }

  void inv(TreeNode* root) {
    if (root == NULL) {
      return;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    inv(root->left);
    inv(root->right);
  }
};












  return 0;
}