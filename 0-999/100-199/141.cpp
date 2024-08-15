#include <bits/stdc++.h>

using namespace std;

int main(){






// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode *pf = head;
      ListNode *ps = head;

      while (pf != NULL && pf->next != NULL) {
        pf = pf->next->next;
        ps = ps->next;

        if (pf == ps) {
          return true;
        }
      }
      return false;
    }
};










  return 0;
}