# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Queue atau antrian adalah salah satu struktur data linier yang proses penyisipan dan penghapusannya mengikuti prinsip FIFO (First In First Out), yaitu elemen yang pertama masuk akan diproses pertama kali. Secara konseptual, queue bekerja seperti antrean di kehidupan nyata, di mana orang yang datang terlebih dahulu akan dilayani lebih dulu.

Struktur data queue terdiri dari dua pointer utama, yaitu head (depan) dan tail (belakang). Operasi utama pada queue meliputi:
Enqueue = proses menambahkan elemen ke bagian belakang antrian.
Dequeue = proses menghapus elemen dari bagian depan antrian.
IsEmpty = memeriksa apakah antrian kosong.
IsFull = memeriksa apakah antrian penuh (khusus static queue).

Pada implementasinya, queue dapat dibuat menggunakan array (static queue) atau linked list (dynamic queue). Queue berbasis array memiliki ukuran yang tetap, sehingga terdapat kondisi penuh, sedangkan queue berbasis linked list bersifat dinamis dan hanya dibatasi oleh memori.

Menurut literatur, queue sering digunakan dalam berbagai proses komputasi seperti penjadwalan CPU, buffering data, manajemen printer, dan simulasi sistem antrian. Implementasi queue memungkinkan proses berjalan secara lebih teratur dan efisien dalam manajemen alur data.

Beberapa penelitian di Indonesia menyebutkan bahwa struktur data queue sangat penting untuk pemrograman terstruktur dan algoritmik. Misalnya, penelitian dalam jurnal oleh Nugroho menjelaskan bahwa queue membantu dalam penerapan algoritma antrian dan pengolahan proses berurutan pada sistem komputer [1]. Penelitian lain oleh Rahmawati menegaskan bahwa queue merupakan salah satu struktur data dasar yang sering digunakan dalam pengembangan perangkat lunak dan pemecahan masalah komputasi [2].

## Guided 

### 1. Guided 1

### queue.h
```C++
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

```

### queue.cpp
```C++
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

```

### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);

    
return 0;
}
```

queue pakai linked list, jadi antriannya sifatnya dinamis dan bisa nambah data selama memori masih ada.
CreateQueue = ini buat nyiapin queue kosong, head dan tail diset ke NULL.
isEmpty = ngecek apakah antrian kosong, cukup lihat head-nya NULL atau nggak.
enQueue =  masukin data baru ke belakang antrian. Kalau antrian kosong, head dan tail jadi node baru. Kalau udah ada isinya, node baru tinggal disambung ke tail.
deQueue =  ngeluarin data paling depan. Tinggal hapus node head dan geser head ke node berikutnya.
viewQueue =  nampilin semua isi antrian dari depan sampai belakang.
clearQueue =  ngehapus semua elemen dengan cara nge-dequeue satu-satu.

### 2. Guided 2

### queue.h
```C++
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
```

### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAXSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0; 
}
```

Queue pakai array statis. Queue tetap bekerja dengan sistem FIFO (First In First Out). Bedanya, karena pakai array, kita harus ngatur head dan tail dengan beberapa cara.
Ada 3 implementasi yang dijelasin:
1. Implementasi 1 Head Diam, Tail Bergerak
head tetap di index awal.
tail maju tiap ada data baru.
Waktu dequeue, semua elemen digeser ke kiri.
Kelemahan: banyak operasi geser → kurang efisien.
2. Implementasi 2 Head & Tail Bergerak
head maju tiap dequeue.
tail maju tiap enqueue.
Tidak perlu geser-geser array.
Tapi kalau tail sudah mentok belakang, tidak bisa dipakai lagi walaupun ada slot kosong di depan.
3. Implementasi 3 Circular Queue
Head dan tail bisa muter (pakai mod %).
Ruang array dimanfaatkan penuh.
Ini implementasi paling efisien.
Fungsi-fungsinya
CreateQueue = inisialisasi queue kosong (head = tail = -1)
isEmpty = cek queue kosong
isFull = cek queue penuh (beda logika per implementasi)
enQueue = masukin data baru sesuai aturan implementasi
deQueue = hapus data paling depan
viewQueue = nampilin semua isi queue


## Unguided 

### 1. Soal 1

### Queue.h
```C++
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
```

### Queue.cpp
```C++
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
```

### Main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue_AL1(Q);

    cout<<"-----------------------------"<<endl;
    cout<<"H - T \t | Queue info"<<endl;
    cout<<"-----------------------------"<<endl;

    printInfo_AL1(Q);
    enqueue_AL1(Q, 5); printInfo_AL1(Q);
    enqueue_AL1(Q, 2); printInfo_AL1(Q);
    enqueue_AL1(Q, 7); printInfo_AL1(Q);
    dequeue_AL1(Q); printInfo_AL1(Q);
    enqueue_AL1(Q, 4); printInfo_AL1(Q);
    dequeue_AL1(Q); printInfo_AL1(Q);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan7_Modul7/ScreenshotOutput_Modul7/Output_Queue.png)

3 macam queue pakai array ukuran 5. Bedanya cuma di cara head dan tail bergerak.
Alternatif 1  Head Diam, Tail Bergerak
head selalu di index 0.
tail maju terus setiap enqueue.
Pas dequeue, elemen digeser ke kiri karena head-nya nggak ikut pindah.
Simple tapi paling capek karena tiap hapus harus geser array.
Cocok buat latihan dasar queue array.
Alternatif 2  Head Bergerak, Tail Bergerak
head dan tail sama-sama maju.
Tidak perlu menggeser elemen.
Problem: kalau tail sudah mentok di ujung array, queue dianggap penuh meskipun ada space kosong di depan.
Ini lebih efisien dari alternatif 1.
Alternatif 3  Circular Queue
Head & tail muter dengan operasi mod (%).
Ruang array dipakai maksimal.
Tidak ada space yang “terbuang”.
Ini implementasi queue terbaik untuk array.
Efisien, cepat, dan tidak boros space.
Fungsi-Fungsi yang Dipakai
createQueue_ALx() = reset head/tail sesuai versi
isEmpty / isFull = cek kondisi queue
enqueue = masukin data
dequeue = ngeluarin data FIFO
printInfo = lihat isi queue dan posisi head/tail


## Kesimpulan
Queue bekerja dengan sistem FIFO, yaitu data yang masuk pertama akan keluar lebih dulu. Struktur data ini bisa dibuat dengan linked list maupun array, dan masing-masing punya cara kerja berbeda seperti queue biasa, queue dengan head-tail bergerak, hingga circular queue. Intinya, queue dipakai untuk mengatur proses yang harus berjalan berurutan dan sangat berguna dalam banyak aplikasi pemrograman.

## Referensi
[1] Nugroho A., 2019. Analisis Implementasi Struktur Data Queue dalam Pengolahan Data Secara FIFO. Jurnal Teknologi dan Sistem Informasi, Vol. 6 No. 2.
<br>[2] Rahmawati, N., 2021. Penerapan Struktur Data Antrian (Queue) pada Aplikasi Pemrosesan Data Berbasis C++. Jurnal Informatika Universitas Pamulang, Vol. 5, No. 1.
<br>[3] Sari, D.P., 2020. Implementasi Antrian Menggunakan Metode Circular Queue pada Sistem Pelayanan. Jurnal Komputer Bisnis, Vol. 14 No. 3.
<br>[4] Triono, R., 2018. Perancangan Struktur Data Queue Menggunakan Linked List pada Sistem Penjadwalan. Jurnal Ilmiah Teknologi dan Informasi, Vol. 7 No. 2.
