#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "LinkedListInterface.h"
#include <string>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
    class node{
    public:
        T val;
        node* next = nullptr;
        node* prev = nullptr;
        node (T myNode) : val(myNode){};
    };

    node* head;
    node* tail;

public:

    LinkedList(void) {
        head = nullptr;
        tail = nullptr;
    };
    ~LinkedList(void) {};

    /*
    insertHead

    A node with the given value should be inserted at the beginning of the list.

    Do not allow duplicate values in the list.
    */
    void insertHead(T value){};

    /*
    insertTail

    A node with the given value should be inserted at the end of the list.

    Do not allow duplicate values in the list.
    */
    void insertTail(T value){};

    /*
    insertAfter

    A node with the given value should be inserted immediately after the
    node whose value is equal to insertionNode.

    A node should only be added if the node whose value is equal to
    insertionNode is in the list. Do not allow duplicate values in the list.
    */
    void insertAfter(T value, T insertionNode){};

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    void remove(T value){};

    /*
    clear

    Remove all nodes from the list.
    */
    void clear(){};

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index){};

    /*
    size

    Returns the number of nodes in the list.
    */
    int size(){};

    /*
    toString

    Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
    There should be no trailing space at the end of the string

    For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
    "1 2 3 4 5"
    */
    string toString(){};

};

#endif //LINKEDLIST_LINKEDLIST_H
