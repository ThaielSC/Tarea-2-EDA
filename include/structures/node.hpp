#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
  int data;
  Node *ptrNext;

public:
  Node();
  Node(int, Node *next = nullptr);
  void setData(int value);
  void setNext(Node *);
  int getData();
  Node *getNext();
  void print();
  virtual ~Node();
};
#endif
