#include "structures/linkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::insertFirst(int val) {
  Node *node = new Node(val);
  if (head == nullptr) {
    head = node;
    tail = node;
  } else {
    node->setNext(head);
    head = node;
  }
}

void LinkedList::insertLast(int val) {
  Node *node = new Node(val);

  if (head == nullptr) {
    head = node;
    tail = node;
  } else {
    tail->setNext(node);
    tail = node;
  }
}

void LinkedList::removeFirst() {

  Node *ptr = head;
  if (head != nullptr) {
    head = head->getNext();
    delete ptr;
    if (head == nullptr) {
      tail = nullptr;
    }
  }
}

void LinkedList::remove(int val) {
  Node *ptr = head;
  Node *ptr_prev = nullptr;
  while (ptr != nullptr) {
    if (ptr->getData() == val) {
      // erase node
      if (ptr_prev == nullptr) {
        head = ptr->getNext();
        delete ptr;
        ptr = head;
      } else {
        ptr_prev->setNext(ptr->getNext());
        delete ptr;
        ptr = ptr_prev->getNext();
      }
    } else {
      ptr_prev = ptr;
      ptr = ptr->getNext();
    }
  }
}

void LinkedList::removeAll() {

  while (head != nullptr) {
    removeFirst();
  }
}

Node *LinkedList::find(int val) {
  Node *ptr = head;
  while ((ptr != nullptr) && (ptr->getData() != val)) {
    ptr = ptr->getNext();
  }
  return ptr;
}

void LinkedList::print() {
  Node *ptr = head;
  while (ptr != nullptr) {
    ptr->print();
    std::cout << " -> ";
    ptr = ptr->getNext();
  }
  std::cout << std::endl;
}

Node *LinkedList::getHead() { return head; }

LinkedList::~LinkedList() { removeAll(); }
