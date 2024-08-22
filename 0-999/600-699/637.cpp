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
  vector<double> averageOfLevels(TreeNode* root) {

    vector<double> avg;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int currLevel = 0;
    int currCount = 0;
    double currAvg = 0;
    while (q.size()) {
      TreeNode *node = q.front().first;
      int level = q.front().second;
      q.pop();

      if (level != currLevel) {
        avg.push_back(currAvg);
        currCount = 0;
        currAvg = 0;
        currLevel = level;
      }

      currCount++;
      currAvg = (currAvg / double(currCount)) * (double(currCount) - 1) + double(node->val) / double(currCount);

      if (node->left != NULL) {
        q.push({node->left, level + 1});
      }
      if (node->right != NULL) {
        q.push({node->right, level + 1});
      }
    }

    avg.push_back(currAvg);
    return avg;
  }
};











  return 0;
}