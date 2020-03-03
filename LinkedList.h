#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "LinkedListInterface.h"
#include <string>
#include <sstream>

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
    ~LinkedList(void) = default;

    bool valCheck(T value){
        node* cur = head;
        T temp;
        while(cur){
            temp = cur -> val;
            if (temp == value){
                return false;
            }
            else cur = cur -> next;
        }
        return true;
    };
    /*
    insertHead

    A node with the given value should be inserted at the beginning of the list.

    Do not allow duplicate values in the list.
    */
    void insertHead(T value){
        if (valCheck(value) == false){
            return;
        };

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
        if (valCheck(value) == false){
            return;
        };
        if(tail == nullptr && head == nullptr){
            tail = new node(value);
            head = tail;
        }
        else{
            node* cur = tail;
            cur -> next = new node(value);
            cur -> next -> prev = tail;
            tail = cur -> next;
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
        if (valCheck(value) == false){
            return;
        };


        node* cur = head;
        int counter = 0;

        //get to the right spot
        while (cur && cur->val != insertionNode){
            cur = cur->next;
            counter++;
        }
        if(cur == head){
            insertHead(value);
        } else if (cur){
            //TODO: File1, 3 is put in Before 2 when it should be put in after. Also 50 is added.
            cur -> prev -> next = new node (value);
            cur -> prev -> next -> next = cur;
            cur -> prev -> next -> prev = cur -> prev;
            cur -> prev = cur -> prev -> next;
        }
        //checks if insertion node is in list
        //TODO: make it so it doesnt print off if insertion node isn't in the file.
        else if(!cur) {
            insertTail(value);
            return;
//            tail->next = new node(value);
//            tail->next->prev = tail;
//            tail = tail->next;
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
        //false start
        if (head == nullptr && tail == nullptr){
            return;
        }
        while (cur -> val != value){
            cur = cur -> next;
            if (!cur){
                return;
            }
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
//    void delNode(){
//
//    }

    void clear(){
        node* cur = head;
//        node* temp = cur;
        while (head != nullptr){
            T value = head->val;
            remove(value);

//            temp = cur->next;
//            free(cur);
//            cur = temp;
        }
        head = nullptr;
        tail = nullptr;
    };

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index){
        T value;
        if (head != nullptr) {
            node* cur = head;
            T value = cur->val;
            return(value);
        }
//         if (head == nullptr || index <= 0) {
//            return 0;
//        }
//
//        for (int i = 1; cur != nullptr && i <= index; i++){
//           cur = cur -> next;
//        }
//        if (cur == nullptr){
//            return 0;
//        }
        else{
            return value;
        }
//        return(value);
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
        stringstream ss;
        string myStr;
        if (head == nullptr){
            return "";
        }
        node* temp = head;
        while(temp){
            ss << (temp->val);
            ss << ' ';
            temp = temp->next;
        }
        return ss.str();
    };

};

#endif //LINKEDLIST_LINKEDLIST_H
