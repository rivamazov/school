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
  void inOrder();
  void insert(std::string word);
  bool search(std::string word);
  bool search2(std::string word);
  void deleteWord(std::string word);
  int getPos(char val);
  char getLetter(int val);
  friend std::ostream& operator<<(std::ostream &out,trie &dict);
  unsigned int numWords();
  //find 3 candidates based on wordlength. use heap
  //std::vector<string> findCandidates(std::string partialWord, int k);
  ~trie();
 private:
 	void wipeTrie(node* nd);
 	void inOrder(node* nd);
 	std::string word;
  node *root;

};

#endif
