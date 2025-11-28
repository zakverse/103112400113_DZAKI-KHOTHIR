# <h1 align="center">Laporan Praktikum Modul 10 - TREE (Bagian Pertama)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Struktur data tree merupakan salah satu struktur non-linier yang memungkinkan representasi data secara hierarkis menggunakan simpul (node) yang saling terhubung melalui pointer. Setiap node dapat memiliki satu atau lebih anak (child), dan node tanpa anak disebut daun (leaf) — berbeda dengan struktur linear seperti array atau linked list[1]

salah satu jenis tree yang sering digunakan dalam aplikasi komputasi adalah Binary Search Tree (BST), yaitu binary tree terurut dimana setiap node memenuhi sifat: semua nilai di subtree kiri lebih kecil, dan semua nilai di subtree kanan lebih besar.[1]

Dengan pemodelan BST menggunakan pointer (linked structure), kita memperoleh fleksibilitas dalam alokasi memori secara dinamis, sehingga ukuran tree dapat berubah sesuai kebutuhan tanpa pemborosan memori.[2]

Operasi dasar pada BST — seperti penyisipan (insert), pencarian (search), penghapusan (delete), dan penelusuran (traversal: pre-order, in-order, post-order) — dapat dilakukan relatif efisien, terutama jika tree cukup seimbang, membuat BST cocok untuk menyimpan dan mengelola data terurut.[3]

## Guided 

### 1. Guided 1

### bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);


void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);

node mostRight(BinTree tree);
node mostLeft(BinTree tree);

void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);


#endif
```

### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```

### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Kode ini mengimplementasikan Binary Search Tree (BST), di mana setiap node (struct BST) menyimpan nilai (angka) dan memiliki anak kiri (left) dan anak kanan (right). Fungsi dasarnya adalah createTree dan isEmpty untuk inisialisasi dan pemeriksaan kekosongan. Untuk mengelola memori, ada alokasi (membuat node baru) dan dealokasi (menghapus node). Fungsi kunci BST adalah insertNode yang menempatkan data baru di posisi yang terurut (lebih kecil ke kiri, lebih besar ke kanan), dan searchByData untuk mencari nilai tertentu dan menampilkan detail hubungannya (parent, sibling, child). Ada tiga metode traversal (kunjungan) untuk menampilkan data: preOrder (Tengah-Kiri-Kanan), inOrder (Kiri-Tengah-Kanan, menghasilkan urutan terurut), dan postOrder (Kiri-Kanan-Tengah). Untuk operasi lanjutan, fungsi deleteNode menangani penghapusan data dengan empat kasus berbeda, dibantu oleh mostLeft (mencari nilai terkecil di sub-pohon kanan untuk penggantian) dan mostRight (mencari nilai terbesar di sub-pohon kiri). Terakhir, size menghitung total node, height menghitung kedalaman/tinggi pohon, dan deleteTree menghapus seluruh pohon secara rekursif.

## Unguided 

### 1. Binary Search Tree menggunakan Linked list

### Bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef struct Node* address;

struct Node {
    int info;
    address left;
    address right;
};

//1
address alokasi(int x);
void insertNode(address &root , int x);
address findNode(int x, address root);
void inOrder(address root);

//2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

//3
void preOrder(address root);
void postOrder(address root);

void reverseInOrder(address root);

#endif

```

### Bstree.cpp
```C++
#include "Bstree.h"
#include <iostream>
using namespace std;

address alokasi(int x){
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL; 
    return p;
}
void insertNode(address &root , int x){
    if (root == NULL){
        root = alokasi(x);
    } else if (x < root->info){
        insertNode(root->left , x);
    } else if (x > root->info){
        insertNode(root->right , x);
    }
}
address findNode(int x, address root){
    if (root == NULL){
        return NULL;
    } else if (x == root->info){
        return root;
    } else if (x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}
void inOrder(address root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->info << " - ";
        inOrder (root->right);
    }
}

//2
int hitungJumlahNode(address root){
    if (root == NULL){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}
int hitungTotalInfo(address root, int start){
    if (root == NULL){
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}
int hitungKedalaman(address root, int start){
    if (root == NULL){
        return -1;
    } else {
        int kiri = hitungKedalaman(root->left, start);
        int kanan = hitungKedalaman(root->right, start);
        int kedalaman;
        if (kiri > kanan){
            kedalaman = kiri;
        } else {
            kedalaman = kanan;
        }
        return kedalaman + 1;   
    }
    cout << endl;
}


//3
void preOrder(address root){
    if ( root != NULL){
        cout << root->info << " - ";
        preOrder (root->left);
        preOrder (root->right);
    }
}
void postOrder(address root){
    if ( root != NULL){
        postOrder (root->left);
        postOrder (root->right);
        cout << root->info << " - ";
    }
}

void reverseInOrder(address root){
    if (root != NULL){
        reverseInOrder(root->right);
        cout << root->info << " - ";
        reverseInOrder(root->left);
    }
}
```

### Main.cpp
```C++
#include "Bstree.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World!" << endl;
    address root = NULL;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    
    inOrder(root);

    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root, 0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;   

    cout<<"\n";
    cout << "Pre Order : ";
    preOrder(root);
    cout << "\nPost Order : ";
    postOrder(root);
    cout << endl;
    cout << "Reverse In Order : ";
    reverseInOrder(root);
    cout << endl;


    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan10_Modul10/ScreenshotOutput_Modul10/Output_BST.png)


kode ini adalah struct Node yang merepresentasikan satu kotak data di pohon, dilengkapi dengan info (nilai) dan pointer ke kiri dan kanan. Fungsi alokasi bertanggung jawab untuk membuat kotak data baru ini. Untuk membangun pohon, fungsi utamanya adalah insertNode, yang secara otomatis menempatkan nilai baru ke kiri jika lebih kecil, atau ke kanan jika lebih besar, menjaga sifat terurut BST. Jika kita perlu mencari data tertentu, fungsi findNode akan menelusuri pohon sesuai dengan aturan BST sampai data ditemukan. Kemudian, ada tiga metode utama untuk membaca seluruh isi pohon (traversal): preOrder (membaca node dulu, baru anak kiri dan kanan), inOrder (membaca anak kiri, lalu node, lalu anak kanan—yang menghasilkan urutan data terurut), dan postOrder (membaca anak kiri dan kanan dulu, baru node-nya). Selain traversal biasa, ada juga reverseInOrder yang membaca data secara terurut menurun. Terakhir, terdapat fungsi-fungsi untuk analisis pohon: hitungJumlahNode untuk mengetahui berapa banyak data yang tersimpan, hitungTotalInfo untuk menjumlahkan semua nilai, dan hitungKedalaman untuk mengetahui seberapa tinggi pohon tersebut, yang semuanya menggunakan teknik rekursif untuk bekerja.


## Kesimpulan
Binary Search Tree (BST) itu sederhananya adalah bentuk pohon yang tiap nodenya nyimpen data dan punya maksimal dua anak: kiri dan kanan. Bedanya dengan pohon biasa, BST punya aturan khusus kalau datanya lebih kecil disimpan ke kiri, kalau lebih besar disimpan ke kanan. Karena itu proses nyari data, nambah data baru, sampai ngapus data bisa jadi lebih cepat dan rapi.

## Referensi
[1] Algoritma dan Struktur Data: Binary Tree & Binary Search Tree (BST)”https://adoc.pub/algoritma-dan-struktur-data-binary-tree-binary-search-tree-b.html?utm
<br>[2] “Penerapan Teori Pohon dalam Kajian Struktur Data” https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2006-2007/Makalah/Makalah0607-24.pdf?utm
<br>[3]“Implementasi Binary Search Tree pada Struktur Data”https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2018-2019/Makalah/Makalah-Matdis-2018-087.pdf?utm

