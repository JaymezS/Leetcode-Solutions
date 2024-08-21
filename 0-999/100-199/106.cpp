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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() && postorder.size()) {
      TreeNode *root = new TreeNode(postorder.back());


      postorder.pop_back();
      for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == root->val) {
          vector<int> larr(inorder.begin(), inorder.begin() + i);
          vector<int> rarr(inorder.begin() + i + 1, inorder.end());

          root->right = buildTree(rarr, postorder);
          root->left = buildTree(larr, postorder);
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
