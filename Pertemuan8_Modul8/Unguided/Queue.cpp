#include <iostream>
#include "queue.h"
using namespace std;

// ALternatif 1 (head diam, tail bergerak).
void createQueue_AL1(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
     for (int i = 0; i < 5; i++)
        Q.info[i] = 0;
}
bool isEmptyQueue_AL1(Queue Q){
    return Q.tail == -1;
}
bool isFullQueue_AL1(Queue Q){
    return Q.tail == 4;
}
void enqueue_AL1(Queue &Q , int x){
    if (isFullQueue_AL1(Q)){
        cout << "Queue Penuh" << endl;
    }else{
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}
int dequeue_AL1(Queue &Q){
     if (isEmptyQueue_AL1(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.head;
    for(int i = Q.head ; i < Q.tail ; i++){
        Q.info[i] = Q.info[i + 1];

    }
    Q.tail--;

    return x;
}

void printInfo_AL1(Queue Q){
    cout << Q.head << " - " << Q.tail << " \t | Queue info = ";
     if (isEmptyQueue_AL1(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for(int i = Q.head ; i <= Q.tail ; i++){
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

//Alternatif 2  (head bergerak, tail bergerak).
void createQueue_AL2(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
 
}
bool isEmptyQueue_AL2(Queue Q){
    return Q.head == -1;
}
bool isFullQueue_AL2(Queue Q){
    return Q.tail == 4 ;
}
void enqueue_AL2(Queue &Q , int x){
    if (isFullQueue_AL2(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if(isEmptyQueue_AL2(Q)){
        Q.head = Q.tail = 0 ;
    }else{
        Q.tail++;
    }
    Q.info[Q.tail] = x ;

}

int dequeue_AL2(Queue &Q){
    if (isEmptyQueue_AL2(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];
    if (Q.head == Q.tail){
        Q.head = Q.tail = -1;
    }else {
        Q.head++;
    }
    return x;
}
void printInfo_AL2(Queue Q){
     cout << Q.head << " - " << Q.tail << " | info = ";

    if (isEmptyQueue_AL2(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++)
        cout << Q.info[i] << " ";

    cout << endl;
}

//Alternatif 3  (head dan tail berputar)
void createQueue_AL3(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}
bool isEmptyQueue_AL3(Queue Q){
    return Q.count == 0;
}
bool isFullQueue_AL3(Queue Q){
    return Q.count == 5;
}
void enqueue_AL3(Queue &Q , int x){
    if (isFullQueue_AL3(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    Q.tail = (Q.tail + 1 ) % 5;
    Q.info[Q.tail] = x;
    Q.count++;

}
int dequeue_AL3(Queue &Q){
    if (isEmptyQueue_AL3(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    int x = Q.info[Q.head];
    Q.head = (Q.head + 1) % 5;
    Q.count--;

    return x;
}
void printInfo_AL3(Queue Q){
    cout << "Head=" << Q.head << " Tail=" << Q.tail << " | ";

    if (isEmptyQueue_AL3(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    cout << "info = ";
    int idx = Q.head;
    for (int i = 0; i < Q.count; i++) {
        cout << Q.info[idx] << " ";
        idx = (idx + 1) % 5;
    }
    cout << endl;
}