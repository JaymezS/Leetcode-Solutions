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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) {
      return head;
    }

    int n = 0;
    ListNode *iter = head;
    while (iter != NULL) {
      iter = iter->next;
      n++;
    }

    int rotNum = k % n;

    if (rotNum == 0) {
      return head;
    }

    // got the number of rotations to do

    iter = head;
    ListNode *newHead;
    for (int i = 0; i < n - rotNum - 1; i++) {
      iter = iter->next;
    }
    newHead = iter->next;
    iter->next = NULL;

    iter = newHead;
    while (iter->next != NULL) {
      iter = iter->next;
    }
    iter->next = head;

    return newHead;
  }
};










  return 0;
}