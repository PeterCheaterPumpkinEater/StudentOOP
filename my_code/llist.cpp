#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (nd == nullptr) {return os;}
    os << nd -> data;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (head->next != nullptr) {add_at_end(head -> next, d);}
    else{
        head->next = new Node(d, nullptr);
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    if (curr != nullptr) {
        cout << curr << ' ';
        print_list(os, curr -> next);
    }
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (head == nullptr) {return nullptr;}
    else if (head -> next == nullptr) {return head;}
    else {return last(head -> next);}
}

bool del_head(Node*& head) {
    if (head == nullptr) {return false;}
    else {
        Node* temp = head -> next;
        delete head;
        head = temp;
        return true;
    }
}

bool del_tail(Node*& head) {
    if (head == nullptr) {return false;}
    else if (head -> next == nullptr) {return del_head(head);}
    else {return del_tail(head -> next);}
}

Node* duplicate(Node* head) {
    if (head == nullptr) {return nullptr;}
    else {return new Node(head -> data, duplicate(head -> next));}
}

Node* reverse(Node* curr, Node* new_next) {
    if (curr == nullptr) {return nullptr;}
    else if (curr -> next == nullptr) {return new Node(curr -> data, new_next);}
    else {
        Node* new_node = new Node(curr -> data, new_next);
        return reverse(curr -> next, new_node);}
}

Node* join(Node*& list1, Node* list2) {
    last(list1) -> next = list2;
    return list1;
}


