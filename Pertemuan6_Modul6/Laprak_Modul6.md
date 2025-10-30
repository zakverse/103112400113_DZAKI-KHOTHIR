# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Struktur data adalah cara penyimpanan dan pengorganisasian data agar dapat diakses serta diubah secara efisien dalam program komputer. Salah satu struktur data yang penting adalah linked list atau senarai berantai, yaitu kumpulan elemen (simpul/node) yang saling terhubung menggunakan pointer atau referensi alamat memori [3][4].
Linked list mendukung alokasi dinamis ukuran list dapat berubah sesuai kebutuhan — berbeda dengan array yang statis. Buku ajar menyebutkan bahwa linked list merupakan struktur linear namun elemen-elemennya tidak harus berada di lokasi memori yang berdekatan karena terhubung melalui pointer [2].

### A. Karakteristik Linked List

Setiap node terdiri atas dua bagian utama: data/informasi dan pointer (atau referensi) ke node lain.

Alokasi dan dealokasi node dilakukan secara dinamis (misalnya dengan new/delete dalam C++).

Akses terhadap elemen bukan berdasarkan indeks seperti array, melainkan melalui traversal mulai dari kepala (head) hingga ke elemen yang diinginkan [1].

### B. Jenis-jenis Linked List

Menurut buku ajar Indonesia:

Singly Linked List — setiap node hanya memiliki pointer ke node selanjutnya (next). Traversal hanya satu arah.

Doubly Linked List — setiap node memiliki dua pointer: ke node berikutnya (next) dan ke node sebelumnya (prev). Traversal maju dan mundur dapat dilakukan. [2][3]

Circular Linked List — node terakhir menunjuk kembali ke node pertama, membentuk struktur melingkar sehingga tidak ada node yang menunjuk ke NULL. [1]

## Guided 

### 1. Guided 1

### ListMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
//#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### ListMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == NULL){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = NULL;
    List.last = NULL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = NULL;
    node->prev = NULL;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != NULL){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != NULL){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NULL) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != NULL && nodeNext->prev != NULL){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### Main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NULL;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program ini menggunakan Doubly Linked List untuk menyimpan data makanan yang berisi nama, jenis, harga, dan rating.
Struktur data node memiliki dua pointer, yaitu next dan prev, sehingga data bisa diakses dari dua arah.
File ListMakanan.h berisi deklarasi struktur dan fungsi, sedangkan ListMakanan.cpp berisi implementasi fungsinya.

Fungsi utama yang digunakan di sini antara lain:
createList membuat list baru yang masih kosong.
alokasi membuat node baru dan mengisi datanya.
insertFirst, insertLast, insertAfter, insertBefore → menambahkan node di posisi tertentu dalam list.
updateFirst, updateLast, updateBefore, updateAfter → mengubah data pada node tertentu.
printList menampilkan semua isi list.

### 2. Guided 2

### ListMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

### ListMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

### Main.cpp
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Program ini lanjutan dari konsep Doubly Linked List pada Guided 1, tapi fiturnya jauh lebih lengkap.
Struktur data linkedlist menyimpan dua pointer, first dan last, yang mengarah ke awal dan akhir list. Setiap elemen (node) berisi data makanan berupa nama, jenis, harga, dan rating, serta dua pointer next dan prev.

Fungsi-fungsi yang digunakan dibagi menjadi beberapa bagian:
Fungsi Dasar

createList membuat list kosong.

isEmpty mengecek apakah list kosong.

alokasi dan dealokasi → membuat dan menghapus node dari memori.
Operasi Penambahan Data

insertFirst, insertLast, insertAfter, dan insertBefore digunakan untuk menambah node di posisi tertentu, baik di awal, akhir, setelah, atau sebelum node lain.
Menampilkan Data

printList akan menampilkan semua node dari awal hingga akhir, lengkap dengan nama, jenis, harga, dan rating.
Update Data

Ada beberapa versi fungsi update seperti updateFirst, updateLast, updateAfter, dan updateBefore.
Masing-masing memungkinkan pengguna mengganti isi data pada posisi tertentu di list tanpa harus membuat node baru.
Pencarian (Searching)

findByName, findByJenis, dan findByMinRating digunakan untuk mencari data makanan berdasarkan nama, jenis, atau minimal rating.

Penghapusan (Delete)

Fungsi seperti deleteFirst, deleteLast, deleteAfter, deleteBefore, dan deleteByName berfungsi menghapus node tertentu dari list sesuai posisi atau nama makanan.

Bagian main.cpp

Program membuat beberapa node makanan (Nasi Rames, Ayam Geprek, Risol Mayo, Mie Ayam, Donat) lalu dimasukkan ke list dengan berbagai posisi.

Setelah itu dilakukan update data, pencarian berdasarkan nama, dan penghapusan beberapa node.

Di akhir, list ditampilkan lagi untuk melihat hasil akhir setelah operasi dilakukan.



## Unguided 

### 1. Soal DoublyLinkedlist

### DoublyList.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
using namespace std;

struct Kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList{
    Kendaraan Info;
    address prev;
    address next;
};

struct List{
    address head;
    address tail;
};

bool IsEmpty(List l);
void CreateList(List &l);
address Alokasi(string nopol, string warna, int thnBuat);
void DeaLokasi(address &p);
void PrintInfo(List l);
void Insertlast(List &l, address p);
address FindElm(List l , string nopol);
void deleteFirst(List &l , address &p);
void deleteLast(List &l , address &p);
void deleteAfter(address prec, address &p);

#endif


```
### DoublyList.cpp
```C++
#include "DoublyList.h"
#include <iostream>
using namespace std;

bool IsEmpty(List l){
    return l.head == NULL;
}
void CreateList(List &l){
    l.head = NULL;
    l.tail = NULL;
}
address Alokasi(string nopol, string warna, int thnBuat){
    address Newnode = new ElmList;
    Newnode->Info.nopol = nopol;
    Newnode->Info.warna = warna;
    Newnode->Info.thnBuat = thnBuat;
    Newnode->prev = NULL;
    Newnode->next = NULL;
    return Newnode;
}
void DeaLokasi(address &p){
    p->next= NULL;
    p->prev = NULL;
    delete p;
}
void PrintInfo(List l){
    if (IsEmpty(l)){cout << " List Kosong " << endl ; return;}

    address current = l.head ;
    cout << "\n======= DATA LIST =======" << endl;
    while (current != NULL){
        cout << "Nomor Polisi\t: " << current->Info.nopol << endl;
        cout << "Warna Kendaraan\t: " << current->Info.warna << endl;
        cout << "Tahun Buat\t: " << current->Info.thnBuat << endl;
        cout << "========================" << endl;
        current = current->next;
    }
    
}
void Insertlast(List &l, address p){
    if (IsEmpty(l)){
        l.head = p;
        l.tail = p;
    }else{
        p->prev = l.tail;
        l.tail->next = p;
        l.tail = p;
    }
    cout << "\nNode " << p->Info.nopol << " Berhasil di tambahkan di bagian tail. " << endl;
}
address FindElm(List l , string nopol){
    if (IsEmpty(l)){
        return NULL;
    }
    address current = l.head ;
    while (current != NULL){
        if (current->Info.nopol == nopol){
            return current;
        }
            current = current->next;
        }
        return NULL;
}
void deleteFirst(List &l , address &p){
    if (IsEmpty(l)){
        cout << " List Kosong " << endl ; 
        return;
    }else{
        address del = l.head;
        l.head = l.head->next;
        l.head->prev = NULL;
        DeaLokasi(del);
    }

}
void deleteLast(List &l , address &p){
    if (IsEmpty(l)){
        cout << " List Kosong " << endl ; 
        return;
    }else{
        address del = l.tail;
        l.tail = l.tail->prev;
        l.tail->next = NULL;
        DeaLokasi(del);
    }
}
void deleteAfter(address prec, address &p){
    p = prec->next;
    prec->next = NULL;
    DeaLokasi(p);
}
```


### Main.cpp
```C++
#include "DoublyList.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    int n;
    cout << "Berapa banyak data kendaraan yang ingin dimasukkan? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string nopol, warna;
        int tahun;

        cout << "\nMasukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> tahun;
        cin.ignore();

        // cek duplikat nopol
        if (FindElm(L, nopol) != NULL) {
            cout << "Nomor polisi sudah terdaftar!\n";
        } else {
            address P = Alokasi(nopol, warna, tahun);
            Insertlast(L, P);
        }
    }

    cout << "\nDATA LIST 1" << endl;
    PrintInfo(L);

    
    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    getline(cin, cariNopol);

    address hasil = FindElm(L, cariNopol);
    if (hasil != NULL) {
        cout << "\n====================================================" << endl;
        cout << "Nomor Polisi : " << hasil->Info.nopol << endl;
        cout << "Warna        : " << hasil->Info.warna << endl;
        cout << "Tahun        : " << hasil->Info.thnBuat << endl;
        cout << "====================================================" << endl;

    } else {
        cout << "Data tidak ditemukan.\n";
    }

   
    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapusNopol);

    address del = FindElm(L, hapusNopol);
    if (del == NULL) {
        cout << "Data tidak ditemukan.\n";
    } else if (del == L.head) {
        deleteFirst(L, del);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus (FIRST)." << endl;
    } else if (del == L.tail) {
        deleteLast(L, del);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus (LAST)." << endl;
    } else {
        address prec = del->prev;
        deleteAfter(prec, del);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus (AFTER)." << endl;
    }

    cout << "\nDATA LIST 1 setelah penghapusan" << endl;
    PrintInfo(L);

    return 0;
}
```


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan6_Modul6/ScreenshotOutput_Modul6/Output_Print.png)


##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan6_Modul6/ScreenshotOutput_Modul6/Output_Cari.png)


##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan6_Modul6/ScreenshotOutput_Modul6/Output_Delete.png)


program ini mengelola data kendaraan yang berisi nomor polisi, warna, dan tahun pembuatan. Pada awalnya, list dibuat kosong menggunakan fungsi CreateList, kemudian pengguna diminta memasukkan sejumlah data kendaraan. Setiap kali data dimasukkan, program memeriksa apakah nomor polisi sudah ada di dalam list menggunakan fungsi FindElm. Jika belum ada, maka data baru dialokasikan dengan Alokasi dan dimasukkan ke bagian akhir list menggunakan InsertLast. Setelah semua data dimasukkan, program menampilkan seluruh isi list melalui fungsi PrintInfo.

Selanjutnya, pengguna dapat mencari data kendaraan berdasarkan nomor polisi. Fungsi FindElm digunakan untuk menelusuri node dari head hingga tail untuk menemukan data yang cocok, lalu menampilkan hasilnya. Program juga menyediakan fitur penghapusan data berdasarkan nomor polisi. Jika data yang ingin dihapus berada di bagian awal list, maka digunakan fungsi deleteFirst; jika di bagian akhir digunakan deleteLast; sedangkan jika berada di tengah, digunakan deleteAfter. Setelah penghapusan, list akan ditampilkan kembali agar terlihat hasil perubahan datanya.

## Kesimpulan
Doubly Linked List merupakan salah satu struktur data dinamis yang memungkinkan akses dua arah melalui pointer next dan prev. Struktur ini lebih fleksibel dibandingkan singly linked list karena memudahkan proses penyisipan dan penghapusan data di berbagai posisi (awal, tengah, maupun akhir list) tanpa harus melakukan traversal penuh.

## Referensi
[1] Hari Soetanto, Struktur Data – Dasar-Dasar Pemrograman, Universitas Budi Luhur, 2022. URL: https://labict.budiluhur.ac.id/wp-content/uploads/2022/06/strukturdata-Perpusr-2022.pdf
<br>[2] Universitas Amikom Yogyakarta, Buku Ajar Struktur Data, 2023.
<br>[3] Tim Penulis, Buku Ajar Algoritma dan Struktur Data, Sonpedia Publishing Indonesia, 2024. 
ResearchGate
<br>[4] Modul Kuliah, Linked List, Universitas Esa Unggul, 2022
