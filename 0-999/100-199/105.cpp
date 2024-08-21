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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (inorder.size()) {
      TreeNode *root = new TreeNode(preorder[0]);

      int n = preorder.front();
      preorder.erase(preorder.begin());
      for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == n) {
          vector<int> larr(inorder.begin(), inorder.begin() + i);
          vector<int> rarr(inorder.begin() + i + 1, inorder.end());
          root->left = buildTree(preorder, larr);
          root->right = buildTree(preorder, rarr);
        }
      }
      return root;
    } else {
      return NULL;
    }
  }
};






  return 0;
}