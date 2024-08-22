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
  int m = INT_MAX;
  int prev = NULL;
  int getMinimumDifference(TreeNode* root) {
    if (root->left) {
      getMinimumDifference(root->left);
    }

    if (prev != NULL) {
      m = min(root->val - prev, m);
    }
    prev = root->val;

    if (root->right) {
      getMinimumDifference(root->right);
    }

    return m;
  }
};










  return 0;
}