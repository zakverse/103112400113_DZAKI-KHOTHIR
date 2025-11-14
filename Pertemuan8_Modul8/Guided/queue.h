#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(const queue &Q);
bool isFull(const queue &Q);   
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(const queue &Q);
void clearQueue(queue &Q);

#endif
