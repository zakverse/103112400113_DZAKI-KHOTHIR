#include "queue.h"
#include <iostream>

using namespace std;

void CreateQueue(queue &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

bool isEmpty(const queue &Q) {
    return Q.head == NULL;
}

bool isFull(const queue &Q) {
    return false;
}

void enQueue(queue &Q, const std::string &nama) {
    Node* baru = new Node();   // allocate node
    baru->nama = nama;
    baru->next = NULL;

    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;

    Q.head = Q.head->next;

    if (Q.head == NULL) {
        Q.tail = NULL;
    }

    delete hapus;
}

void viewQueue(const queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    int i = 1;
    for (Node* p = Q.head; p != NULL; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
