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
  int kthSmallest(TreeNode* root, int k) {
    vector<TreeNode *> s;
    s.push_back(root);
    int c = 0;

    while (s.size()) {
      TreeNode *node = s.back();
      s.pop_back();

      

      if (node->right) {
        s.push_back(node->right);
        node->right = NULL;
      }
      if (node->left) {
        s.push_back(node);
        s.push_back(node->left);
        node->left = NULL;
      } else {
        c++;
        if (c == k) {
          return node->val;
        }
      }
    }
    return -1;
  }
};










  return 0;
}