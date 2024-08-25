#include <bits/stdc++.h>


using namespace std;


int main() {



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if (node->neighbors.size() == 0) {
            return new Node(node->val);
        }
        unordered_map<Node*, Node*> d;
        queue<Node*> q;
        q.push(node);
        while (q.size()) {
            Node* n = q.front();
            q.pop();
            Node* clone;
            if (!d.count(n)) {
                clone = new Node(n->val);
            } else {
                clone = d[n];
            }

            for (auto& nexts: n->neighbors) {
                if (!d.count(nexts)) {
                    d[nexts] = new Node(nexts->val);
                    q.push(nexts);
                }
                clone->neighbors.push_back(d[nexts]);
            }

        }


        return d[node];
    }
};




  return 0;
}