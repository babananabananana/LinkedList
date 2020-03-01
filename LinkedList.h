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
    void insertHead(T value){
        if (head == nullptr && tail == nullptr){
            head = new node(value);
            tail = head;
        }else{
            node* cur = head;
            cur -> prev = new node(value);
            cur -> prev -> next = head;
            head = cur -> prev;
        }
    };

    /*
    insertTail

    A node with the given value should be inserted at the end of the list.

    Do not allow duplicate values in the list.
    */
    void insertTail(T value){
        if(tail == nullptr && head == nullptr){
            tail = new node(value);
            head = tail;
        }
        else{
            node* cur = tail;
            cur -> next = new node(value);
            cur -> next -> prev = tail;
            tail = cur-> next;
        }

    };

    /*
    insertAfter

    A node with the given value should be inserted immediately after the
    node whose value is equal to insertionNode.

    A node should only be added if the node whose value is equal to
    insertionNode is in the list. Do not allow duplicate values in the list.
    */
    void insertAfter(T value, T insertionNode){
        node* cur = head;
        while (cur && cur->val != insertionNode){
            cur = cur->next;
        }
        if (cur){
           cur -> prev -> next = new node (value);
            cur -> prev -> next -> next = cur;
            cur -> prev -> next -> prev = cur -> prev;
            cur -> prev = cur -> prev -> next;
        }
        else if(!cur) {
            tail->next = new node(value);
            tail->next->prev = tail;
            tail = tail->next;
        }
        return;
    };

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    void remove(T value){
        node* cur = head;
        while (cur -> val != value){
            cur = cur -> next;
            if (!cur){
                return;
            }
        }
        if (head == nullptr && tail == nullptr){
            return;
        }
        //if rmv val = head.
        if (head -> val == value){
            head = head -> next;
        }
        //if rmv val != tail, change next
        if (cur -> next != nullptr){
            cur -> next -> prev = cur -> prev;
        }
        // if rmv val != first, change prev.
        if (cur -> prev != nullptr){
            cur -> prev -> next = cur -> next;
        }
        free(cur);
    };

    /*
    clear

    Remove all nodes from the list.
    */
    void clear(){
        node* cur = head;
        node* temp = cur;
        while (cur){
            temp = cur->next;
            free(cur);
            cur = temp;
        }
    };

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index){
        if (head == nullptr || index < 0) {
            return 0;
        }
        node* cur = head;
        for (int i = 1; cur != nullptr && i <= index; i++){
           cur = cur -> next;
        }
        if (cur == nullptr){
            return 0;
        }
        T value = cur->val;
        return(value);
    };

    /*
    size

    Returns the number of nodes in the list.
    */
    int size(){
        node* cur = head;
        int counter = 0;
        while (cur != nullptr){
            counter++;
            cur = cur -> next;
        }
        return counter;
    };

    /*
    toString

    Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
    There should be no trailing space at the end of the string

    For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
    "1 2 3 4 5"
    */
    string toString(){
        string myStr;
        node* temp = head;
        while(temp){
            myStr += (temp->val);
            myStr.push_back(' ');
            temp = temp->next;
        }
        return myStr;
    };

};

#endif //LINKEDLIST_LINKEDLIST_H
