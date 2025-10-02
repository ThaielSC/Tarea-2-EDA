#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "structures/node.hpp"

class LinkedList {
private:
  Node *head;

public:
  LinkedList();
  void insertFirst(int);
  void insertLast(int);
  void removeFirst();
  void removeLast();
  void remove(int);
  void removeAll();
  Node *find(int);
  void print();
  virtual ~LinkedList();
};
#endif
