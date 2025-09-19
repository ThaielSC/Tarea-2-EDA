#include "structures/linkedList.hpp"
#include <iostream>

Node::Node(int data) : data(data), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Inserts at the end of the list in O(1)
void LinkedList::insert(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
