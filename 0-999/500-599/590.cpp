#include <bits/stdc++.h>

using namespace std;

int main(){





/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



class Solution {
public:
  vector<int> postorder(Node* root) {
    if (root == NULL) {
      return {};
    }
    vector<pair<Node *, bool>> s;
    vector<int> res;
    s.push_back({root, false});

    while (s.size()) {
      Node *n = s.back().first;
      bool visited = s.back().second;
      s.pop_back();

      if (visited) {
        res.push_back(n->val);
      } else {
        s.push_back({n, true});
        for (int i = n->children.size() - 1; i >= 0; i--) {
          s.push_back({n->children[i], false});
        }
      } 
    }
    return res;
  }
};










  return 0;
}