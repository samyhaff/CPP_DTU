#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    if (q == nullptr) return nullptr;
    else if (q->ticket == ticket) return q;
    else return find(q->next, ticket);
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    if (q == nullptr)
        return nullptr;
    else if (q->ticket == ticket)
        return q->next;
    else {
        q->next = remove(q->next, ticket);
        return q;
    }
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    if (q == nullptr)
        return nullptr;

    if (q->priority) {
        Passenger *new_q = new Passenger;
        *new_q = *q;
        new_q->next  = priority(q->next);
        return new_q;
    } else {
        return priority(q->next);
    }
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
