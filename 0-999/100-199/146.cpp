#include <bits/stdc++.h>

using namespace std;

int main(){


class Node {
public:
  int key;
  int val;
  Node *next;
  Node *prev;

  Node(int _key, int _val)
  {
    key = _key;
    val = _val;
    next = NULL;
    prev = NULL;
  }
};



class LRUCacheBad {
public:
  unordered_map<int, Node*> table;
  int maxCap;
  int currCap = 0;
  Node *currHead = NULL;
  Node *currTail = NULL;
  LRUCacheBad(int capacity) {
    maxCap = capacity;
  }
  
  int get(int key) {
    Node *sent = currHead;
    while (sent != NULL) {
      std::cout << sent->key << ":" << sent->val << ", ";
      sent = sent->next;
    }
    std::cout << endl;
    if (table.count(key)) {
      if (currTail == table[key]) {
        currTail = table[key]->prev;
      }
      if (currHead == table[key]) {
        currHead = table[key]->next;
      }
      if (table[key]->next != NULL) {
        table[key]->next->prev = table[key]->prev;
      }
      if (table[key]->prev != NULL) {
        table[key]->prev->next = table[key]->next;
      }

      table[key]->next = currHead;
      table[key]->prev = NULL;
      if (currHead) {
        currHead->prev = table[key];
      }
      if (currTail == NULL) {
        currTail = table[key];
      }
      currHead = table[key];
      return table[key]->val;
    }
    return -1;
  }
  
  void put(int key, int value) {
    Node *sent = currHead;
    while (sent != NULL) {
      std::cout << sent->key << ":" << sent->val << ", ";
      sent = sent->next;
    }
    std::cout << endl;
    Node *n = new Node(key, value);

    if (table.count(key)) {
      if (currTail == table[key]) {
        currTail = table[key]->prev;
      }
      if (currHead == table[key]) {
        currHead = table[key]->next;
      }
      if (table[key]->next != NULL) {
        table[key]->next->prev = table[key]->prev;
      }
      if (table[key]->prev != NULL) {
        table[key]->prev->next = table[key]->next;
      }
      currCap--;
    } else if (currCap >= maxCap) {
      table.erase(currTail->key);
      currTail = currTail->prev;
      if (currTail) {
        currTail->next = NULL;

      }
    }
    table[key] = n;
    n->next = currHead;

    if (currHead) {
      currHead->prev = n;
    }
    currHead = n;
    currCap++;
    if (currTail == NULL) {
      currTail = n;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LRUCache {
public:
  unordered_map<int, Node*> table;
  int maxCap;
  int currCap = 0;
  Node *currHead = NULL;
  Node *currTail = NULL;
  LRUCache(int capacity) {
    maxCap = capacity;
  }

  void placeNode(Node * node) {
    node->next = currHead;
    node->prev = NULL;
    if (currHead) {
      currHead->prev = node;
    }
    currHead = node;
    if (currTail == NULL) {
      currTail = node;
    }
  }

  void removeNode(int key) {
    if (currTail == table[key]) {
        currTail = table[key]->prev;
      }
      if (currHead == table[key]) {
        currHead = table[key]->next;
      }
      if (table[key]->next != NULL) {
        table[key]->next->prev = table[key]->prev;
      }
      if (table[key]->prev != NULL) {
        table[key]->prev->next = table[key]->next;
    }
  }
  
  int get(int key) {

    if (table.count(key)) {
      removeNode(key);
      placeNode(table[key]);
      return table[key]->val;
    }
    return -1;
  }
  
  void put(int key, int value) {
    Node *n = new Node(key, value);

    if (table.count(key)) {
      removeNode(key);
      currCap--;
    } else if (currCap >= maxCap) {
      int k = currTail->key;
      removeNode(k);
      table.erase(k);
    }
    table[key] = n;
    placeNode(n);
    currCap++;

  }
};







  return 0;
}