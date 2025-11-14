#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

struct Queue
{
    int info[5];
    int head ;
    int tail;

    int count;  // alternatif 3
};

// ALternatif 1 (head diam, tail bergerak)
void createQueue_AL1(Queue &Q);
bool isEmptyQueue_AL1(Queue Q);
bool isFullQueue_AL1(Queue Q);
void enqueue_AL1(Queue &Q , int x);
int dequeue_AL1(Queue &Q);
void printInfo_AL1(Queue Q);

//Alternatif 2 (head bergerak, tail bergerak).
void createQueue_AL2(Queue &Q);
bool isEmptyQueue_AL2(Queue Q);
bool isFullQueue_AL2(Queue Q);
void enqueue_AL2(Queue &Q , int x);
int dequeue_AL2(Queue &Q);
void printInfo_AL2(Queue Q);

//Alternatif 3  (head dan tail berputar)
void createQueue_AL3(Queue &Q);
bool isEmptyQueue_AL3(Queue Q);
bool isFullQueue_AL3(Queue Q);
void enqueue_AL3(Queue &Q , int x);
int dequeue_AL3(Queue &Q);
void printInfo_AL3(Queue Q);


#endif