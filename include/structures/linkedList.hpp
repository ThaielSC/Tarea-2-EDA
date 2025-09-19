#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node {
    int data;
    Node* next;

    Node(int data);
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList();
    ~LinkedList();

    void insert(int data);
};

#endif // LINKEDLIST_HPP
