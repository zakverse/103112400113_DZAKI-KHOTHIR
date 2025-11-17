#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

bool isEmpty(QueueEkspedisi Q){
    return Q.tail == -1;
}
bool isFull(QueueEkspedisi Q){
    return Q.tail == MAX - 1;
}
void createQueue(QueueEkspedisi &Q){
    Q.head = -1;
    Q.tail = -1;
}
void enqueue(QueueEkspedisi &Q , Paket data){
    if (isFull(Q)){
        cout << "Queue Penuh" << endl;
    }else{
        if(isEmpty(Q)){
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = data ;
    }
}
Paket dequeue(QueueEkspedisi &Q){
    Paket data;
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return data;
    }
    data = Q.info[Q.head];
    if (Q.head == Q.tail){
        Q.head = Q.tail = -1;
    }else {
        Q.head++;
    }
    return data;
}
void viewQueue(QueueEkspedisi Q){
    cout << Q.head << " - " << Q.tail << " | info = ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << "Kode Resi: " << Q.info[i].KodeResi << ", ";
        cout << "Nama Pengirim: " << Q.info[i].NamaPengirim << ", ";
        cout << "Berat Barang: " << Q.info[i].BeratBarang << "kg, ";
        cout << "Tujuan: " << Q.info[i].Tujuan << endl;
    }
    cout << endl;
}

float TotalBiayaPengiriman(QueueEkspedisi Q, int biayaPerKg){
    float totalBiaya = 0.0;
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return totalBiaya;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        totalBiaya += Q.info[i].BeratBarang * biayaPerKg;
    }
    return totalBiaya;
}