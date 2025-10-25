# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Linked List atau senarai berantai merupakan salah satu bentuk struktur data dinamis yang digunakan untuk menyimpan sekumpulan data secara berurutan, di mana setiap elemen data disebut sebagai node dan dihubungkan dengan pointer atau referensi [1]. Setiap node pada singly linked list biasanya terdiri dari dua bagian utama, yaitu bagian data yang menyimpan nilai (seperti angka atau informasi lain), dan bagian next yang menunjuk ke node berikutnya. Tidak seperti array yang memiliki ukuran tetap, linked list bersifat dinamis sehingga ukurannya dapat bertambah atau berkurang selama program berjalan [2].

Struktur data linked list banyak digunakan dalam berbagai aplikasi karena sifatnya yang fleksibel dalam manajemen memori. Linked list memungkinkan proses penambahan dan penghapusan data dilakukan tanpa perlu memindahkan elemen-elemen lain di memori, berbeda dengan array yang memerlukan penggeseran elemen. Kelebihan ini membuat linked list efisien dalam operasi insert dan delete di posisi mana pun dalam list. Namun, linked list juga memiliki kelemahan yaitu waktu akses yang lebih lambat karena pencarian data harus dilakukan dengan menelusuri node satu per satu dari awal hingga ditemukan node yang diinginkan [3].

## Guided 

### 1. listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```


### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```


### 3. main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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
Pada bagian guided, programnya pakai struktur data singly linked list untuk menyimpan data beberapa buah.
Masing-masing node punya tiga isi utama: nama buah, jumlah, dan harga, lalu disambungkan pakai pointer next.
Program ini dibagi jadi tiga file: header (listBuah.h), implementasi (listBuah.cpp), dan main.cpp.

Bagian Header (listBuah.h)
Di sini didefinisikan semua tipe data dan fungsi yang bakal dipakai.
Ada struct buah untuk data, struct node untuk tiap simpul, dan struct linkedlist buat menyimpan pointer first.
Fungsi-fungsinya meliputi operasi dasar kayak buat list, insert node, delete node, update, dan searching.

Bagian Implementasi (listBuah.cpp)
Di bagian ini semua fungsi di header dijalankan satu-satu.

createList() bikin list kosong.
insertFirst, insertAfter, insertLast buat nambah node di posisi berbeda.
delFirst, delAfter, delLast buat hapus node.
updateFirst, updateAfter, updateLast buat ubah data buah di posisi tertentu.

FindNodeByData, FindNodeByAddress, dan FindNodeByRange buat cari data buah berdasarkan isi, alamat, atau harga tertentu.
Program ini juga pakai fungsi nbList() buat ngitung jumlah node dan deleteList() buat hapus semua data.

Bagian main.cpp
Di sini semua fungsi tadi dites. Pertama, program bikin beberapa node (Jeruk, Apel, Pir, Semangka, Durian) dan disusun ke dalam list lewat kombinasi insert.
Setelah itu dilakukan update data, pencarian, dan penghapusan node untuk memastikan semua fungsi jalan dengan benar.
Output-nya nunjukin isi list sebelum dan sesudah setiap operasi, biar bisa dilihat perubahan datanya secara langsung.


## Unguided 

### 1. ListAngka.h

```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct Node *address;

struct Node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};


void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);
bool IsEmpty(linkedList L);

void updateFirst(linkedList &L , dataAngka newVal);
void updateLast(linkedList &L , dataAngka newVal);
void updateAfter(linkedList &L, address prec, dataAngka newVal);
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, int nilaiMin);

int Tambah(linkedList L);
int Kurang(linkedList L);
int Kali(linkedList L);
#endif

```
### 2. ListAngka.cpp

```C++
#include "ListAngka.h"

void CreateList(linkedList &L){
    L.first = NULL ;
}

bool IsEmpty(linkedList L){
    return L.first == NULL;
}

address alokasi(dataAngka x){
    address p = new Node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address p){
    delete p;
    p = NULL;
}

void printList(linkedList L){
    address p = L.first;
    cout << "Isi Dari List :" << endl;
    if(IsEmpty(L)){
        cout << "Data Kosong " << endl;
    }else{
        while(p != NULL){
            cout << p->angka;
            if (p->next != NULL) {cout << " -> ";}
            p = p->next;
        }
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p){
    if(IsEmpty(L)){
        L.first = p ;
        p->next = NULL;
    }else{
        p->next = L.first;
        L.first = p;
    }
}

void insertLast(linkedList &L, address p){
    if (IsEmpty(L)){
        insertFirst(L , p);
    }else{
       address current = L.first;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = p;
        }
}

void insertAfter(linkedList &L, address p, address prec){
    p->next = prec->next;
    prec->next = p;
}

//nbList itu Count 
int nbList(linkedList L){
    if(IsEmpty(L)){
        cout << "List Kosong" << endl ;
        return 0;
    }else{
        int count = 0;
        address current = L.first;  
        while(current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }
}

void delAfter(linkedList &L, address &p, address prec){
    if(IsEmpty(L)){
        cout << "Data Kosong" << endl;
        p = NULL;
    }else if (prec == NULL || prec->next == NULL){
        cout << "Tidak Ada Next nya" << endl;
        p = NULL;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
        cout << "Node setelah " << prec->angka << " berhasil dihapus." << endl;
    }
}

void updateFirst(linkedList &L , dataAngka newVal){
    if (!IsEmpty(L))
        L.first->angka = newVal;
}

void updateLast(linkedList &L , dataAngka newVal){
    if (IsEmpty(L)) return;
    address current = L.first;
    while(current->next != NULL){
        current = current->next;
    }
    current->angka = newVal;
}

void updateAfter(linkedList &L, address prec , dataAngka newVal){
   if (prec != NULL && prec->next != NULL)
        prec->next->angka = newVal;
}

void SearchByData(linkedList L, int data){
    address current = L.first;
    bool found = false ;
    while (current->angka == data){
        cout << "Data " << data << " ditemukan di alamat " << current << endl;
        found = true;
    }

    if (!found){ cout << "Data " << data << " tidak ditemukan." << endl;}
}

void SearchByAddress(linkedList L, address node){
    address current = L.first;
    bool found = false;
    while(current != NULL){
        if(current == node){
            cout << "Alamat " << node << " ditemukan dengan nilai " << current->angka << endl;
            found = true;
            break;
        }
        current = current->next;
    }
    if(!found){
        cout << "Alamat " << node << " tidak ditemukan di list.\n";
    }
}

void SearchByRange(linkedList L, int nilaiMin){
    address current = L.first;
    bool found = false;
    cout << "Data dengan nilai >= " << nilaiMin << ":\n";
    while(current != NULL){
        if(current->angka >= nilaiMin){
            cout << "  " << current->angka << " (alamat " << current << ")\n";
            found = true;
        }
        current = current->next;
    }
    if(!found){
        cout << "Tidak ada data di atas " << nilaiMin << endl;
    }
}


int Tambah(linkedList L){
    int total = 0;
    address current = L.first;
    while(current != NULL){
        total = total + current->angka;
        current = current->next;
    }
    return total;
}

int Kurang(linkedList L){
    int total = 0;
    address current = L.first;
    while(current != NULL){
        total = total - current->angka;
        current = current->next;
    }
    return total;
}

int Kali(linkedList L){
    int total = 1;
    address current = L.first;
    while(current != NULL){
        total = total * current->angka;
        current = current->next;
    }
    return total;
}
```


### 3. Main.cpp

```C++
#include <iostream>
#include "ListAngka.h"
using namespace std;

int main(){
    linkedList L;
    CreateList(L);
    address del = NULL;

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);           //  B
    insertLast(L, nodeA);           // B -> A
    insertAfter(L, nodeD, nodeB);  //  B: B -> D -> A
    insertFirst(L, nodeC);        // C -> B -> D -> A
    insertLast(L, nodeE);        // C -> B -> D -> A -> E
    insertFirst(L, nodeF);      // F -> C -> B -> D -> A -> E
    
    delAfter(L, del, nodeC);
    cout << "\n== List setelah operasi insert & delete ==\n";
    printList(L);
    cout << "============================" << endl;

    updateFirst(L, 50);
    updateAfter(L, nodeD, 29);
    updateLast(L, 45);
    updateAfter(L, nodeF, 20);

    cout << "\n== List setelah update =="<< endl;
    printList(L);
    cout << "============================" << endl;

    cout << "Hasil Penjumlahan = " << Tambah(L) << endl;
    cout << "Hasil Pengurangan = " << Kurang(L) << endl;
    cout << "Hasil Perkalian = " << Kali(L) << endl;
    cout << "============================" << endl;

}
```

### Output Unguided  :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan5_Modul5/ScreenshotOutput_Modul5/Output_ListAngka.png)


Struktur Data (ListAngka.h)
Isinya tipe data dasar Node (menyimpan angka dan pointer next) serta struct linkedList yang menyimpan pointer first.
Ada juga deklarasi fungsi untuk operasi standar linked list kayak insert, delete, update, dan searching, plus tambahan operasi aritmetika (Tambah, Kurang, Kali).

Implementasi (ListAngka.cpp)
Di file ini tiap fungsi diimplementasikan satu-satu:

Insert & Delete: sama kayak guided, tapi dengan data integer.

Update: bisa ubah nilai node pertama, terakhir, atau setelah node tertentu.

Searching: bisa cari data berdasarkan nilai, alamat, atau range nilai tertentu.

Aritmetika: program bisa ngitung jumlah, selisih, dan hasil kali semua angka di dalam list.

Program Utama (main.cpp)
Di bagian ini list diisi dengan beberapa angka (8, 13, 18, 25, 33, 40).
Setelah itu dilakukan kombinasi operasi seperti insert di awal, tengah, dan akhir, delete node setelah elemen tertentu, lalu update beberapa nilai di node.
Setelah semua manipulasi selesai, program menampilkan hasil operasi aritmetika (penjumlahan, pengurangan, perkalian) dari seluruh isi list.
Output-nya memperlihatkan hasil setiap operasi sehingga gampang dicek apakah pointer dan alur data sudah benar.

## Kesimpulan
Singly Linked List merupakan struktur data dinamis yang efisien untuk manipulasi data yang sering berubah, karena penambahan dan penghapusan elemen dapat dilakukan dengan mudah tanpa perlu menggeser data lain. Melalui implementasi fungsi update dan searching, dapat memahami bagaimana melakukan perubahan serta pencarian data pada struktur yang saling terhubung

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara.
<br>[2] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
<br>[3] Yuliana. (2018). Struktur Data – Linked List. Surabaya: Politeknik Elektronika Negeri Surabaya.
