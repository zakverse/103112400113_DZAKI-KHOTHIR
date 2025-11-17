#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <iostream>
using namespace std;

struct Paket{
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

const int MAX = 5;

struct QueueEkspedisi{
    Paket info[MAX];
    int head;
    int tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q , Paket data);
Paket dequeue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);
float TotalBiayaPengiriman(QueueEkspedisi Q, int biayaPerKg);
#endif