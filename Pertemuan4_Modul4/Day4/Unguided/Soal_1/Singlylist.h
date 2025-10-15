#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *first;
};

void createList(List &L);
Node* createNode(int x);
void insertFirst(List &L, Node *p);
void insertLast(List &L, Node *p);
void insertAfter(Node *prec, Node *p);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node *prec);
void printList(List L);
int nbList(List L);
void deleteList(List &L);

#endif
