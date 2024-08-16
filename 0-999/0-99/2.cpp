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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = false;

    ListNode *t1 = l1;
    ListNode *t2 = l2;
    while (t2->next != NULL && t1->next != NULL) {
      int s = t1->val + t2->val;
      if (c) {
        s++;
      }
      if (s > 9) {
        c = true;
        s -= 10;
      } else {
        c = false;
      }
      t1->val = s;
      t2->val = s;

      t1 = t1->next;
      t2 = t2->next;
    }
    int s = t1->val + t2->val;
    if (c) {
      s++;
    }
    if (s > 9) {
      c = true;
      s -= 10;
    } else {
      c = false;
    }
    t1->val = s;
    t2->val = s;


    if (t1->next == NULL && t2->next == NULL) {
      if (c) {
        ListNode *newNode = new ListNode;
        newNode->val = 1;
        t1->next = newNode;
        c = false;
      }
      return l1;
    } else if (t1->next == NULL) {
      while (c) {
        if (t2->next != NULL) {
          int n = t2->next->val + 1;
          if (n >= 10) {
            t2->next->val = 0;
          } else {
            t2->next->val = n;
            c = false;
          }
          t2 = t2->next;
        } else {
          ListNode *newNode = new ListNode;
          newNode->val = 1;
          t2->next = newNode;
          c = false;
        }
      }
      return l2;
    } else {
      while (c) {
        if (t1->next != NULL) {
          int n = t1->next->val + 1;
          if (n >= 10) {
            t1->next->val = 0;
          } else {
            t1->next->val = n;
            c = false;
          }
          t1 = t1->next;
        } else {
          ListNode *newNode = new ListNode;
          newNode->val = 1;
          t1->next = newNode;
          c = false;
        }
      }
      return l1;
    }
  }
};









  return 0;
}