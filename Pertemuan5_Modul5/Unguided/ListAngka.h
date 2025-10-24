#ifndef LISTANGKA_H
#define LISTANGKA_H
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct Node *address;

struct Node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};


void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);
bool IsEmpty(linkedList L);

void updateFirst(linkedList &L , dataAngka newVal);
void updateLast(linkedList &L , dataAngka newVal);
void updateAfter(linkedList &L, address prec, dataAngka newVal);
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, int nilaiMin);
#endif
