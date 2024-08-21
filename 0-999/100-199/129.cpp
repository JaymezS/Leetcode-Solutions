#include <bits/stdc++.h>

using namespace std;

int main(){

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
  int sumNumbers(TreeNode* root) {
    int total = 0;
    stack<pair<TreeNode *, int>> q;
    q.push({root, root->val});

    while (q.size()) {
      TreeNode *node = q.top().first;
      int currSum = q.top().second;
      q.pop();
      if (node->left == NULL && node->right == NULL) {
        total += currSum;
        continue;
      }
      if (node->left != NULL) {
        q.push({node->left, currSum * 10 + node->left->val});
      }
      if (node->right != NULL) {
        q.push({node->right, currSum * 10 + node->right->val});
      }
    }    
    
    return total;
  }
};











  return 0;
}