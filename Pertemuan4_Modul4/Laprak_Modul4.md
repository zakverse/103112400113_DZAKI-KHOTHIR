# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Struktur data linked list merupakan kumpulan elemen yang disebut node, di mana setiap node menyimpan data dan alamat ke node berikutnya [1]. Berbeda dengan array, linked list memiliki ukuran dinamis sehingga memudahkan proses penambahan dan penghapusan data [2].

Terdapat beberapa jenis linked list seperti singly linked list, doubly linked list, dan circular linked list [3]. Pada singly linked list, setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya. Sedangkan pada doubly linked list, terdapat dua pointer yang memungkinkan penelusuran maju maupun mundur [4].
## Guided 

### 1. Guided 1 

### SLL.h
```C++
#ifndef SLL_H
#define SLL_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &Node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

```

### SLL.cpp
```C++
#include "SLL.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```

### main.cpp
```C++
#include "SLL.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

File SLL.h berisi deklarasi ADT, seperti struktur data node, mahasiswa, dan fungsi-fungsi dasar seperti insertFirst,
insertAfter dan insertLast.
File SLL.cpp berisi implementasi fungsi-fungsi tersebut, termasuk alokasi dan dealokasi node.
File main.cpp digunakan untuk menguji hasil operasi insert dengan membuat beberapa data mahasiswa, lalu menampilkan seluruh isi list menggunakan printList()

### 2. Guided 2

### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &Node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```

### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}


void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
   
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}



int nbList(linkedlist List) {
   
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}


void deleteList(linkedlist &List){
  
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
}

```

### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Pada Guided 2, konsep yang sama dari Guided 1 dikembangkan dengan penambahan operasi 
penghapusan node dan penghitungan jumlah node.
Tambahan fungsi-fungsi di sini antara lain:
delFirst() untuk menghapus node pertama,delLast() untuk menghapus node terakhir,delAfter() untuk menghapus node setelah posisi tertentu,nbList() untuk menghitung jumlah node,deleteList() untuk menghapus seluruh isi list.

## Unguided 

### 1. Soal 1

### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *first;
};

void createList(List &L);
Node* createNode(int x);
void insertFirst(List &L, Node *p);
void insertLast(List &L, Node *p);
void insertAfter(Node *prec, Node *p);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node *prec);
void printList(List L);
int nbList(List L);
void deleteList(List &L);

#endif

```

### Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

Node* createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void insertFirst(List &L, Node *p) {
    p->next = L.first;
    L.first = p;
}

void insertAfter(Node *prec, Node *p) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node *p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node *q = L.first;
            while (q->next->next != NULL) {
                q = q->next;
            }
            delete q->next;
            q->next = NULL;
        }
    }
}

void deleteAfter(Node *prec) {
    if (prec != NULL && prec->next != NULL) {
        Node *p = prec->next;
        prec->next = p->next;
        delete p;
    }
}

void printList(List L) {
    Node *p = L.first;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node *p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}

```

### Main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, createNode(0));
    insertFirst(L, createNode(2));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(9));
    insertFirst(L, createNode(12));

    cout << "List awal: ";
    printList(L);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan4_Modul4/ScreenshotOutput_Modul4/Output_Soal1.png)

Program Unguided 1 bertujuan mengimplementasi dasar dari operasi penambahan node (insert) pada Singly Linked List dengan tipe data integer.
Fungsi insertFirst() digunakan untuk menambah node di depan list secara berurutan, lalu printList() menampilkan hasil akhirnya.

### 2. Soal 2

### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *first;
};

void createList(List &L);
Node* createNode(int x);
void insertFirst(List &L, Node *p);
void insertLast(List &L, Node *p);
void insertAfter(Node *prec, Node *p);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node *prec);
void printList(List L);
int nbList(List L);
void deleteList(List &L);

#endif

```

### Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

Node* createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void insertFirst(List &L, Node *p) {
    p->next = L.first;
    L.first = p;
}

void insertAfter(Node *prec, Node *p) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node *p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node *q = L.first;
            while (q->next->next != NULL) {
                q = q->next;
            }
            delete q->next;
            q->next = NULL;
        }
    }
}

void deleteAfter(Node *prec) {
    if (prec != NULL && prec->next != NULL) {
        Node *p = prec->next;
        prec->next = p->next;
        delete p;
    }
}

void printList(List L) {
    Node *p = L.first;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node *p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}

```

### Main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, createNode(0));
    insertFirst(L, createNode(2));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(9));
    insertFirst(L, createNode(12));

    cout << "List awal: ";
    printList(L);


    deleteFirst(L);                                                                                                          
    cout << "Setelah deleteFirst: ";
    printList(L);

    
    deleteLast(L);
    cout << "Setelah deleteLast: ";
    printList(L);


    deleteAfter(L.first);
    cout << "Setelah deleteAfter: ";
    printList(L);

    cout << "\nJumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan4_Modul4/ScreenshotOutput_Modul4/Output_Soal2.png)



Program Unguided 2 merupakan lanjutan dari soal 1 dengan tambahan operasi penghapusan dan perhitungan node.

deleteFirst() menghapus elemen pertama,deleteLast()  menghapus elemen terakhir,deleteAfter()  menghapus node setelah posisi tertentu,nbList() menghitung jumlah node yang tersisa,deleteList() menghapus seluruh list.

## Kesimpulan
Singly Linked List merupakan struktur data dinamis yang fleksibel untuk menyimpan data dalam urutan tertentu.
Proses penyisipan (insert) dan penghapusan (delete) node.
Cara menghitung jumlah elemen dalam list.
Manajemen memori menggunakan alokasi dan dealokasi dinamis.
Struktur ini penting karena menjadi dasar dari berbagai struktur data kompleks seperti stack, queue, dan graph.

## Referensi
[1] A. R. Setiawan, “Implementasi Struktur Data Linked List pada Bahasa Pemrograman C++,” Jurnal Teknologi dan Sistem Informasi (JTSI), Universitas Muhammadiyah Sidoarjo, Vol. 5, No. 1, 2019. https://doi.org/10.21070/jtsi.v5i1.2332
<br>[2] M. Mulyadi, “Analisis dan Implementasi Struktur Data Linked List pada Pengelolaan Data Mahasiswa,” Jurnal Teknologi Informasi dan Komunikasi (JTIK), Universitas Kristen Duta Wacana, 2018. https://journal.ukdw.ac.id/index.php/jtik/article/view/296
<br>[3] E. Nugroho, Struktur Data Menggunakan C++, Andi Publisher, Yogyakarta, 2018.
<br>[4] A. Kadir, Algoritma dan Pemrograman Menggunakan C++, Andi Publisher, Yogyakarta, 2014.

