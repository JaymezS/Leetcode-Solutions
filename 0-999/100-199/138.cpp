#include <bits/stdc++.h>

using namespace std;

int main(){




/*
// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) {
      return NULL;
    }
    unordered_map<Node *, Node *> d;
    Node *iter = head;
    d[iter] = new Node(iter->val);
    while (iter != NULL) {
      if (iter->next == NULL) {
        d[iter]->next = NULL;
      } else {
        if (!d.count(iter->next)) {
          d[iter->next] = new Node(iter->next->val);
        }
        d[iter]->next = d[iter->next];
      }
      if (iter->random == NULL) {
        d[iter]->random = NULL;
      } else {
        if (!d.count(iter->random)) {
          d[iter->random] = new Node(iter->random->val);
        }
        d[iter]->random = d[iter->random];
      }


      iter = iter->next;
    }

    return d[head];
  }
};











  return 0;
}