#include <bits/stdc++.h>


using namespace std;


int main() {



class Node {
  public:
    bool isWord;
    Node* child[26];
    Node() {
      isWord = false;
      for (int i = 0; i < 26; i++) {
        child[i] = NULL;
      }
    }
};



class Trie {
public:
  Node* root;
  Trie() {
    root = new Node();
  }
  
  void insert(string word) {
    Node* sent = root;
    for (auto& c: word) {
      int x = c - 'a';
      if (!sent->child[x]) {
        sent->child[x] = new Node();
      }
      sent = sent->child[x];
    }
    sent->isWord = true;
  }
  
  bool search(string word) {
    Node* sent = root;
    for (auto& c: word) {
      int x = c - 'a';
      if (!sent->child[x]) {
        return false;
      }
      sent = sent->child[x];
    }
    return sent->isWord;
  }
  
  bool startsWith(string prefix) {
    Node* sent = root;
    for (auto& c: prefix) {
      int x = c - 'a';
      if (!sent->child[x]) {
        return false;
      }
      sent = sent->child[x];
    }

    for (auto& chld: sent->child) {
      if (chld || sent->isWord) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */




  return 0;
}