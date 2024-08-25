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
  vector<int> postorderTraversal(TreeNode* root) {
    if (root == NULL) {
      return {};
    }
    vector<TreeNode *> s;
    s.push_back(root);
    vector<int> order;
    while (s.size()) {
      TreeNode *node = s.back();
      s.pop_back();
      if (node->left == NULL && node->right == NULL) {
        order.push_back(node->val);
      } else if (node->left == NULL ) {
        s.push_back(node);
        s.push_back(node->right);
        node->right = NULL;
      } else if (node->right == NULL) {
        s.push_back(node);
        s.push_back(node->left);
        node->left = NULL;
      } else {
        s.push_back(node);
        s.push_back(node->right);
        s.push_back(node->left);
        node->left = NULL;
        node->right = NULL;
      }
    }
    return order;
  }
};










  return 0;
}