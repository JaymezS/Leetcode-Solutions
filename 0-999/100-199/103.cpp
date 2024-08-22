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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
      return {};
    }
    vector<vector<int>> levels;
    levels.push_back({root->val});
    vector<pair<TreeNode *, int>> q;
    q.push_back({root, 0});

    while (q.size()) {
      TreeNode *node;
      int depth = min(q.front().second, q.back().second);
      if (depth % 2 == 1) {
        node = q.front().first;
        depth = q.front().second;
        q.erase(q.begin());
      } else {
        node = q.back().first;
        depth = q.back().second;
        q.erase(q.end());
      }


      if (depth % 2 == 1) {
        if (levels.size() <= depth + 1) {
            levels.push_back({});
        }
        if (node->left) {q.push_back({node->left, depth + 1}); levels[depth + 1].push_back(node->left->val);}
        if (node->right) {q.push_back({node->right, depth + 1}); levels[depth + 1].push_back(node->right->val);}

      } else {
        if (levels.size() <= depth + 1) {
            levels.push_back({});
        }
        if (node->right) {q.insert(q.begin(), {node->right, depth + 1}); levels[depth + 1].push_back(node->right->val);}
        if (node->left) {q.insert(q.begin(), {node->left, depth + 1}); levels[depth + 1].push_back(node->left->val);}
      }
   
    }

    if (levels.back().empty()) {
      levels.pop_back();
    }
    return levels;
  }
};












  return 0;
}