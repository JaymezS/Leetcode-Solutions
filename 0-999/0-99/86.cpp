#include <bits/stdc++.h>

using namespace std;

int main(){




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
  ListNode* partition(ListNode* head, int x) {
    if (head == NULL) {
      return NULL;
    }
    ListNode *smallHead = new ListNode(0);
    ListNode *largeHead = new ListNode(0);
    ListNode *siter = smallHead;
    ListNode *liter = largeHead;
    while (head != NULL) {
      ListNode *temp = head->next;
      if (head->val < x) {
        siter->next = head;
        head->next = NULL;
        siter = siter->next;
      } else {
        liter->next = head;
        head->next = NULL;
        liter = liter->next;
      }
      head = temp;
    }
    siter->next = largeHead->next;
    return smallHead->next;
  }
};











  return 0;
}