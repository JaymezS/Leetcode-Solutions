#include <bits/stdc++.h>


using namespace std;


int main() {



class Node {

public:
  bool isWord;
  Node* children[26];
  Node() {
    isWord = false;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
};



class WordDictionary {
public:

  Node* root;

  WordDictionary() {
    root = new Node();
  }
  
  void addWord(string word) {
    Node* s = root;
    for (char& c: word) {
      int x = c - 'a';
      if (!s->children[x]) {
        s->children[x] = new Node();
      }
      s = s->children[x];
    }
    s->isWord = true;
  }
  
  bool search(string word) {
    Node* n = root;
    return __search(word, n);
  }


  bool __search(string word, Node* node) {
    if (word.length() == 0) {
      return node->isWord;
    }

    char c = word[0];
    word = word.substr(1, word.size());
    int idx = c - 'a';

    if (c == '.') {
      for (auto& chld: node->children) {
        if (chld) {
          bool res = __search(word, chld);
          if (res) {
            return res;
          }
        }
      }
    } else if (node->children[idx]) {
      return __search(word, node->children[idx]);
    
    } else {
        return false;
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */




  return 0;
}