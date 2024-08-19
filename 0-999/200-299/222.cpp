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
  int countNodes(TreeNode* root) {
    return recurse(root);
  }


  int recurse(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int ldepth = 1;
    TreeNode *temp = root;
    while (temp->left != NULL) {
      temp = temp->left;
      ldepth++;
    }

    int rdepth = 1;
    temp = root;
    while (temp->right != NULL) {
      temp = temp->right;
      rdepth++;
    }

    if (rdepth == ldepth) {
      return (pow(2, rdepth) - 1);
    } else {
      return 1 + recurse(root->left) + recurse(root->right);
    }
  }
};








  return 0;
}