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



class BSTIterator {
public:
  stack<TreeNode *> s;
  BSTIterator(TreeNode* root) {
    p(root);
  }
  
  int next() {
    TreeNode *node = s.top();
    s.pop();
    if (node->right) {
      p(node->right);
    }
    return node->val;
  }
  
  bool hasNext() {
    if (s.size()) {
      return true;
    }
  }

  void p(TreeNode * node) {
    while (node != NULL) {
      s.push(node);
      node = node->left;
    }
  }
};












  return 0;
}
