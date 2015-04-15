#ifndef TRIE_H_
#define TRIE_H_

#define ALPHA 26
#include <string>
#include "node.h"
#include <iostream>

class trie
{
 public:
  trie();
  void insert(std::string word);
  bool search(std::string word);
  void deleteWord(std::string word);
  int getPos(char val);
  friend std::ostream& operator<<(std::ostream &out,trie &dict);
  unsigned int numWords();
  ~trie();
 private:
 	void wipeTrie(node* nd);
  node *root;

};

#endif
