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
  int maxDepth(TreeNode* root) {
    if (root == NULL) {
      return NULL;
    }
    return DFS(root, 1);
  }

  int DFS(TreeNode* root, int d) {
    if (root->left == NULL && root->right == NULL) {
      return d;
    } else {
      if (root->left != NULL && root->right != NULL) {
        return max(DFS(root->right, d+1), DFS(root->left, d + 1));
      } else if (root->right != NULL) {
        return DFS(root->right, d + 1);
      } else {
        return DFS(root->left, d + 1);
      }
    }
  }
};










  return 0;
}