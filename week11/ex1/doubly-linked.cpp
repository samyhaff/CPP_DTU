#include "doubly-linked.h"

List::List() {
    first = nullptr;
}

List::~List() {
    Node *current = first;

    while (current) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
}

void List::insert(int n) {
    Node *new_node = new Node;
    Node *current = first;

    new_node->val = n;
    new_node->next = nullptr;

    if (current == nullptr) {
        first = new_node;
        first->prev = nullptr;
        return;
    }

    while (current->next)
        current = current->next;

    current->next = new_node;
    new_node->prev = current;
}

void List::reverse() {
    Node *current = first, *tmp;

    if (first == nullptr) return;

    while (current->next) {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    tmp = current->prev;
    current->prev = current->next;
    current->next = tmp;
    first = current;
}

void List::print() {
    Node *current = first;

    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
