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
  bool isValidBST(TreeNode* root) {
    queue<pair<TreeNode *, pair<long, long>>> q;
    q.push({root, {LONG_MIN, LONG_MAX}});
    while (q.size()) {
      TreeNode *node = q.front().first;
      long minVal = q.front().second.first;
      long maxVal = q.front().second.second;
      q.pop();
      if (node->val > minVal && node->val < maxVal) {
        if (node->left) {
          q.push({node->left, {minVal, node->val}});
        }
        if (node->right) {
          q.push({node->right, {node->val, maxVal}});
        }
      } else {
        return false;
      }
    }
    return true;
  }
};








  return 0;
}