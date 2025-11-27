#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef struct Node* address;

struct Node {
    int info;
    address left;
    address right;
};

//1
address alokasi(int x);
void insertNode(address &root , int x);
address findNode(int x, address root);
void inOrder(address root);

//2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

//3
void preOrder(address root);
void postOrder(address root);

void reverseInOrder(address root);

#endif
