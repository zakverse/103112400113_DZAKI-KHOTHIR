# <h1 align="center">Laporan Praktikum Modul 7 - STACK </h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Struktur data Stack adalah suatu abstrak data type (ADT) yang menyimpan sekumpulan elemen dengan aturan akses Last-In, First-Out (LIFO), artinya elemen yang paling akhir dimasukkan akan menjadi yang pertama dikeluarkan. Suatu stack memiliki operasi dasar seperti push (menambahkan elemen ke bagian atas), pop (menghapus elemen dari bagian atas), dan peek/top (mengambil elemen di bagian atas tanpa menghapusnya) [1].

Implementasi stack secara umum menggunakan dua pendekatan utama:

Array (statis): elemen disimpan dalam array dengan variabel penunjuk “top” sebagai indeks bagian atas. Pendekatan ini memiliki waktu operasi O(1) untuk push/pop, namun memiliki keterbatasan ukuran tetap (overflow saat penuh) [2].

Linked List (dinamis): elemen disimpan dalam node yang dihubungkan melalui pointer, dengan satu pointer yang menunjuk ke node paling atas (top). Pendekatan ini lebih fleksibel dalam ukuran karena dapat menyesuaikan jumlah elemen secara dinamis, walaupun memerlukan ruang tambahan untuk pointer [3].

Penggunaan stack sangat luas dalam pengembangan perangkat lunak: misalnya untuk pengelolaan undo-redo, navigasi back/forward pada browser, evaluasi ekspresi matematika, traversal grafik, dan manajemen panggilan fungsi (recursion) [4]. Studi juga menunjukkan bahwa pemilihan implementasi (array vs linked list) tergantung pada kebutuhan seperti efisiensi akses atau fleksibilitas ukuran [5].

## Guided 

### 1. Guided 1 Stack Dengan Linked List

### stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Di file stack.h, ditentuin dulu strukturnya: ada node yang isinya data (dataAngka) dan pointer next buat nunjuk ke node berikutnya. Terus ada juga struct stack yang cuma punya satu pointer top — ini yang bakal nyimpen alamat node paling atas di stack. Di sini juga dideklarasiin fungsi-fungsi penting seperti push, pop, update, view, dan searchData
Di stack.cpp, semua fungsi itu dijelasin.
createStack() buat inisialisasi stack biar mulai dari kosong (top = NULL).
push() dipakai buat nambah node baru ke atas stack. Jadi node baru bakal langsung nunjuk ke top lama, lalu top digeser ke node baru itu.
pop() kebalikannya, dia ngapus node paling atas. Tapi dicek dulu apakah stack-nya kosong atau nggak, biar nggak error.
update() bisa dipakai buat ngubah data di posisi tertentu dalam stack. Posisi dihitung dari atas, dan program bakal minta input data baru buat digantiin yang lama.
view() menampilkan semua isi stack dari atas ke bawah, biar kelihatan urutan datanya.
searchData() fungsinya buat nyari nilai tertentu di stack. Kalau ketemu, program bakal ngasih tau di posisi ke berapa data itu berada.
Terakhir, di main.cpp, semua fungsi itu dites


### 2. Guided 2 Stack Dengan Array

### stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
} 

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
    }
    cout << endl;
}

```

### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}


```
Di bagian stack.h, ada definisi struktur stackTable yang nyimpen array data dan variabel top, serta deklarasi semua fungsi penting seperti push, pop, update, view, dan searchData. File stack.cpp isinya implementasi logika dari masing-masing fungsi itu.
Fungsi createStack() buat inisialisasi stack biar mulai dari keadaan kosong.
push() buat nambahin data ke atas stack, tapi sebelum itu dicek dulu pake isFull() biar nggak kelebihan kapasitas.
pop() kebalikannya, dipakai buat ngambil data paling atas. Kalau stack-nya kosong, bakal muncul pesan error.
update() bisa ngubah nilai data di posisi tertentu (dihitung dari atas, bukan dari bawah).
view() dipakai buat nampilin isi stack dari elemen paling atas ke paling bawah.
searchData() buat nyari apakah sebuah nilai ada di dalam stack, dan kalau ketemu, ditunjukkan posisi datanya dari atas.
Terus di main.cpp, semua fungsi itu dites satu-satu. Pertama stack dibuat kosong, terus ditambahin data 1 sampai 5 pake push(). Setelah itu, dua data paling atas dihapus pake pop(), biar bisa kelihatan perubahannya. Selanjutnya ada proses update() buat ubah data di posisi tertentu, dan terakhir dilakukan pencarian data pake searchData(). Output-nya nunjukin semua proses itu secara bertahap, jadi mudah ngelihat gimana data dalam stack berubah setelah tiap operasi.

## Unguided 

### 1. Soal 1

### Stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

const int MAX = 20;

struct Stack{
   int info[MAX];
   int top;
};

bool is_Empty(Stack s);
bool is_Full(Stack s);
void CreateStack(Stack &s);
void push(Stack &s , int x);
void pop(Stack &s);
int popValue(Stack &s);
void printInfo(Stack s);
void balikStack(Stack &s);
void pushAscending(Stack &s , int x);
void getInputStream(Stack &s);


#endif
```
### Stack.cpp
```C++
#include"Stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &s){
    s.top = -1;
}

bool is_Empty(Stack s){
    return (s.top == -1);
}

bool is_Full(Stack s){
    return (s.top == MAX - 1) ;
}

void push(Stack &s , int x){
    if (is_Full(s)){
        cout << "Stack Penuh!" << endl;
    }else{
        s.top++;
        s.info[s.top] = x;
    }
}

void pop(Stack &s){
    if(is_Empty(s)){
        cout << "Stack Kosong" <<endl;
    }else{
        s.top--;
    }
}
int popValue(Stack &s){
    if (is_Empty(s)){
        cout << "Stack Kosong" << endl;
        return -1;
    }else{
     int x = s.info[s.top];
     s.top--;
     return x;
    }
}

void printInfo(Stack s){
    cout << "[TOP] ";
    for (int i = s.top ; i >= 0 ; i--){
        cout << s.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &s){
    Stack temp ;
    CreateStack(temp);
    while(!is_Empty(s)){
        push(temp , popValue(s));
    }
    s = temp;
   
}

void pushAscending(Stack &s, int x) {
    if (is_Full(s)) {
        cout << "Stack penuh!\n";
        return;
    }

    Stack temp;
    CreateStack(temp);

    while (!is_Empty(s) && s.info[s.top] > x) {
        push(temp, popValue(s));
    }

    push(s, x);

    while (!is_Empty(temp)) {
        push(s, popValue(temp));
    }
}

void getInputStream(Stack &s) {
    char c;
    cout << "Masukkan angka (akhiri dengan Enter): ";
    while (cin.get(c) && c != '\n') {
        if (isdigit(c)) {
            push(s, c - '0');
        }
    }
}

```

### Main.cpp
```C++
#include"Stack.h"
#include <iostream>
using namespace std;

int main(){
cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);




    cout << "\n\nHello world!" << endl;
    Stack AS;
    CreateStack(AS);
    pushAscending(AS, 3);
    pushAscending(AS, 4);
    pushAscending(AS, 8);
    pushAscending(AS, 2);
    pushAscending(AS, 3);
    pushAscending(AS, 9);
    printInfo(AS);

    cout << "balik stack" << endl;
    balikStack(AS);
    printInfo(AS);
    

    cout << "\n\nHello world!" << endl;
    Stack IS;
    CreateStack(IS);
    getInputStream(IS);
    printInfo(IS);

    cout << "balik stack" << endl;
    balikStack(IS);
    printInfo(IS);

}
```

### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan7_Modul7/ScreenshotOutput_Modul7/Output_Stack.png)


Struktur programnya dibagi jadi tiga file biar rapi: Stack.h, Stack.cpp, dan Main.cpp. Di file Stack.h ada deklarasi struktur stack dan daftar fungsi-fungsinya. Di Stack.cpp, semua fungsi itu diisi logikanya. Misalnya, CreateStack() buat nyiapin stack kosong, push() buat nambahin data ke atas tumpukan, dan pop() buat ngambil data paling atas. Ada juga fungsi balikStack() yang fungsinya buat ngebalik isi stack, terus pushAscending() yang otomatis nyimpen data biar urut dari kecil ke besar. Fungsi terakhir yaitu getInputStream() biar kita bisa masukin angka langsung dari keyboard dan otomatis disimpen ke dalam stack.
Terus di file Main.cpp, semua fungsi tadi dicoba satu per satu.


## Kesimpulan
Stack itu struktur data sederhana tapi penting banget dalam dunia pemrograman, karena konsepnya sering dipakai di banyak hal kayak undo-redo, pemanggilan fungsi (recursion), sampai compiler.
Implementasi stack bisa dilakukan pakai array atau linked list, tapi di tugas ini kita pakai array biar lebih mudah dan langsung kelihatan index-nya.
Operasi dasar stack (push, pop, balikStack) semuanya bisa dijalanin dengan kompleksitas waktu O(1), alias cepat banget karena langsung akses posisi terakhir.
Tambahan fitur pushAscending dan getInputStream bikin stack-nya lebih fleksibel, karena bisa otomatis urut dan bisa langsung ambil input dari user.
Secara keseluruhan, program ini ngajarin dasar yang kuat buat paham konsep struktur data dan algoritma, terutama bagian tumpukan data dan manipulasi elemen di dalamnya.

## Referensi
[1] Sihombing, J. (2019). Penerapan Stack dan Queue pada Array dan Linked List dalam Java. INFOKOM, 
<br>[2] Amaylia, S., Setiabud, V.A., et al. (2025). Application of Stack Data Structure in Application Development. Journal of Advanced Systems Intelligence and Cybersecurity, 1(01).
<br>[3] Setiyawan, R.D., et al. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH.
<br>[4] Raj, H. (2021). Stack: Data Structure – Implementation in Java using Array, Linked List and ArrayList. Medium. 
[5] OpenDSA contributors. Comparison of Array-Based and Linked Stacks. (lihat analisis implementasi)
