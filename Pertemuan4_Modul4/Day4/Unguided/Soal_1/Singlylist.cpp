#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

Node* createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void insertFirst(List &L, Node *p) {
    p->next = L.first;
    L.first = p;
}

void insertAfter(Node *prec, Node *p) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node *p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node *q = L.first;
            while (q->next->next != NULL) {
                q = q->next;
            }
            delete q->next;
            q->next = NULL;
        }
    }
}

void deleteAfter(Node *prec) {
    if (prec != NULL && prec->next != NULL) {
        Node *p = prec->next;
        prec->next = p->next;
        delete p;
    }
}

void printList(List L) {
    Node *p = L.first;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node *p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}
