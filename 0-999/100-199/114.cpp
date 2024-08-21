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
  void flatten(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    root = recurse({root, root}).first;
  }

  pair<TreeNode*, TreeNode*> recurse(pair<TreeNode*, TreeNode*> startEnd) {
    TreeNode *start = startEnd.first;
    if (start->left == NULL && start->right == NULL) {
      return {start, start};
    }
    pair<TreeNode *, TreeNode *> l = {NULL, NULL};
    pair<TreeNode *, TreeNode *> r = {NULL, NULL};

    if (start->left != NULL) {
      l = recurse({start->left, start->left});
    }
    if (start->right != NULL) {
      r = recurse({start->right, start->right});
    }
    start->left = NULL;
    if (l.first != NULL && r.first != NULL) {
      start->right = l.first;
      l.second->right = r.first;
      return {start, r.second};
    } else if (l.first != NULL) {
      start->right = l.first;
      return {start, l.second};
    } else {
      start->right = r.first;
      return {start, r.second};
    }
  }
};









  return 0;
}