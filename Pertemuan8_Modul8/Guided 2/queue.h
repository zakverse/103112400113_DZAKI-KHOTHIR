#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

const int MAXSIMAL = 5;

struct queue
{
    string nama[MAXSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q , string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif