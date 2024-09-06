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

class SolutionBad {
public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_map<int, bool> s;
    for (auto& n: nums) {
      s[n] = true;
    }
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr) {
      if (s.count(curr->val)) {
        prev->next = curr->next;
      } else {
        prev = curr;
      }        
      curr = curr->next;
    }
    
    return dummy->next; 
  }
};



class Solution {
public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    vector<bool> has(100001, false);
    for (auto& n: nums) {
      has[n] = true;
    }
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr) {
      if (has[curr->val]) {
        prev->next = curr->next;
      } else {
        prev = curr;
      }        
      curr = curr->next;
    }
    
    return dummy->next; 
  }
};






  return 0;
}