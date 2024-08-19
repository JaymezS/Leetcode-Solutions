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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return recurse(p, q);
  }


  bool recurse(TreeNode * p, TreeNode* q) {
    if (p == NULL && q == NULL) {
      return true;
    } else if (p == NULL) {
      return false;
    } else if (q == NULL) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    } else {
      return recurse(p->left, q->left) && recurse(p->right, q->right);
    }
  }
};











}  