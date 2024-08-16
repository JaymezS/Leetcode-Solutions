#include <bits/stdc++.h>

using namespace std;

int main(){

  // NOTE:: Used Code from Q.92: reverse Linked list from given left:int to right:int to simplify answer;

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

  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) {
      return head;
    }
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode *sentinel = head;
    ListNode *headAttacher = dummyHead;
    int c = 0;
    while (sentinel != NULL) {
      c++;
      if (c == k) {
        c = 0;
        headAttacher->next = reverseBetween(head, 1, k);
        sentinel = headAttacher ->next;
        head = headAttacher ->next;
        for (int i = 0; i < k; i++) {
          head = head->next;
          headAttacher = headAttacher->next;
          sentinel = sentinel->next;
        }
      } else {
        sentinel = sentinel->next;
      }
    }

    return dummyHead->next;
  }


  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head->next == NULL) {
      return head;
    }
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;

    int c = 0;
    ListNode *iter = dummyHead;
    while (c < left - 1) {
      iter = iter->next;
      c++;
    }
    ListNode *start = iter;
    iter = iter->next;

    ListNode *end = iter;
    ListNode *prev = iter;
    iter = iter->next;
    ListNode *next;
    while (c < right - 1) {
      next = iter->next;
      iter->next = prev;
      prev = iter;
      iter = next;
      c++;
    }
    start->next = prev;
    end->next = iter;

    return dummyHead->next;
  }
};











  return 0;
}