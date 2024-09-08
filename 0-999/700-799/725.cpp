#include <bits/stdc++.h>


using namespace std;


int main() {



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    ListNode* sent = head;
    int length = 0;
    while (sent) {
      length++;
      sent = sent->next;
    }    
    sent = head;

    int extraNum = length % k;
    int segLength = length / k;
    vector<ListNode*> result(k, NULL);

    if (sent == NULL) {
      return result;
    }

    
    for (int i = 0; i < k && sent; i++) {
      result[i] = sent;
      if (i < extraNum) {
        for (int j = 0; j < segLength; j++) {
          sent = sent->next;
        }
      } else {
        for (int j = 0; j < segLength - 1; j++) {
          sent = sent->next;
        }
      }

      ListNode* temp = sent;
      sent = sent->next;
      temp->next = NULL;
    }

    return result;
  }
};





  return 0;
}