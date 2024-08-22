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
  vector<int> rightSideView(TreeNode* root) {
    if (root== NULL) {
      return {};
    }
    vector<int> topDown;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (q.size()) {
      TreeNode *node = q.front().first;
      int depth = q.front().second;
      q.pop();
      if (topDown.size() <= depth) {
        topDown.push_back(node->val);
      } else {
        topDown[depth] = node->val;
      }
      if (node->left) {
        q.push({node->left, depth + 1});
      }
      if (node->right) {
        q.push({node->right, depth + 1});
      }
    }

    return topDown;
  }
};










  return 0;
}