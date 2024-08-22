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
  int absMax = INT_MIN;

  int maxPathSum(TreeNode* root) {
    rec(root);
    return absMax;
  }


  int rec(TreeNode* root ) {
    if (root->left == NULL && root->right == NULL) {
      absMax = max(absMax, root->val);
      return root->val;
    }

    int lm = NULL;
    int rm = NULL;
    int currMax = root->val;
    if (root->left != NULL) {
      lm = rec(root->left);
      currMax = max(currMax, lm + currMax);
    }
    if (root->right != NULL) {
      rm = rec(root->right);
      currMax = max(currMax, rm + currMax);
    }

    absMax = max(absMax, currMax);
    return max(root->val, max(lm + root->val, rm + root->val));
  }
     
};









  return 0;
}