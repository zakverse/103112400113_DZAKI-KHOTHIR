# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Multi Linked List (MLL) adalah pengembangan dari struktur data linked list yang memungkinkan setiap node memiliki lebih dari satu pointer ke struktur list lain. Dengan kata lain, MLL digunakan untuk merepresentasikan hubungan one-to-many, many-to-many, atau hubungan bertingkat dalam data.[1]

Berbeda dengan single linked list yang hanya memiliki pointer ke node selanjutnya, MLL memungkinkan sebuah node induk (parent) memiliki pointer ke kepala suatu child list yang berisi kumpulan node terkait. Hal ini membuat MLL sangat fleksibel digunakan untuk merepresentasikan struktur data yang kompleks, seperti:[2]

Data mahasiswa (parent) dengan daftar mata kuliah yang diambil (child)
Data produk (parent) dengan daftar transaksi penjualan (child)
Data kategori (parent) dengan daftar item (child)
Dalam implementasinya, setiap elemen parent dan child biasanya dibuat menggunakan struct berbeda, dan hubungan antara keduanya dihubungkan melalui pointer next (untuk sesama parent atau sesama child) serta pointer nextChild (untuk menghubungkan parent ke anak).

MLL memiliki beberapa operasi dasar, seperti:
Insert Parent – Menambahkan elemen parent ke dalam list.
Insert Child – Menambahkan child ke parent tertentu.
Delete Parent – Menghapus parent beserta seluruh child-nya.
Delete Child – Menghapus salah satu child dari parent.
Traversal – Menampilkan parent dan semua child yang terhubung.[6]

Struktur ini dianggap lebih efisien dibandingkan array dua dimensi ketika jumlah child tiap parent bervariasi, karena hanya memakan memori sesuai jumlah data yang benar-benar digunakan.


## Guided 

### 1. Guided MLL 1

### mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

### mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

### main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
Sistem ini mengimplementasikan struktur data Multi Linked List (MLL) untuk mengelola menu restoran, yang memisahkan data menjadi dua tingkatan: Parent atau Induk yang merepresentasikan Kategori Makanan (KategoriMakanan) dan Child atau Anak yang merepresentasikan detail Menu Makanan (DataMakanan). List Induk (listInduk) diimplementasikan sebagai Doubly Linked List yang menampung nodeParent. Setiap nodeParent selain menyimpan data kategori (ID dan nama kategori), juga memiliki Linked List internal (listAnak) yang juga merupakan Doubly Linked List berisi nodeChild. Setiap nodeChild menyimpan detail makanan (ID, nama, dan harga). .File mll.h berisi deklarasi struktur data utama dan semua prototipe fungsi yang mendukung operasi lengkap pada kedua list, seperti membuat list, alokasi/dealokasi, serta operasi manipulasi data (penyisipan, penghapusan, pencarian, dan pembaruan) baik pada Parent (listInduk) maupun Child (listAnak). File mll.cpp menyediakan implementasi dari semua fungsi tersebut. Yang terpenting, operasi penghapusan Parent (deleteFirstParent, deleteLastParent, deleteAfterParent) secara otomatis juga memanggil fungsi hapusListAnak untuk menghapus semua node Child yang terikat dengannya, menjaga integritas memori. Fungsi findChildByID dan updateDataChildByID dirancang untuk mencari/memperbarui Child dengan cara menjelajahi (traverse) seluruh list Parent terlebih dahulu, dan di setiap Parent akan menjelajahi list Child-nya.File main.cpp adalah program utama yang mendemonstrasikan fungsionalitas. Program ini membuat tiga kategori utama (Makanan Berat, Minuman, Dessert), menyisipkan menu-menu spesifik (Child) ke kategori yang sesuai, kemudian menguji semua operasi: menampilkan seluruh struktur (printStrukturMLL), mencari data Parent dan Child, memperbarui nama kategori dan detail makanan, dan diakhiri dengan menghapus menu pertama dari kategori Minuman (deleteFirstChild) dan menghapus kategori terakhir (Dessert) beserta semua menunya (deleteLastParent). Tujuannya adalah untuk memastikan semua operasi dasar MLL, terutama penautan dan penghapusan bertingkat, berfungsi dengan benar.

## Unguided 

### 1. Unguided MultiLinkedList

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
using namespace std;

//================================
struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; //TRUE jika berekor, FALSE jika tidak berekor
    float bobot; // dalam kg
};
//================================

typedef struct nodeChild *address_child;
typedef struct nodeParent *address_parent;

//================================
struct nodeChild{
    dataHewan isidata;
    address_child nextChild;
    address_child prevChild;
};
struct ListChild{
    address_child firstChild;
    address_child lastChild;
};
//================================


//================================
struct nodeParent{
    golonganHewan isidata;
    address_parent nextParent;
    address_parent prevParent;
    ListChild listChild;
};
struct ListParent{
    address_parent firstParent;
    address_parent lastParent;
};
//================================

bool isEmptyParent(ListParent L);
bool isEmptyChild(ListChild L);

void createListParent(ListParent &L);
void createListChild(ListChild &L);

address_parent alokasiParent(string idGolongan, string namaGolongan);
address_child alokasiChild(string idHewan, string namaHewan, string habitat, bool ekor, float bobot);

void dealokasiParent(address_parent &P);
void dealokasiChild(address_child &C);

void insertFirstParent(ListParent &lParent, address_parent newParent);
void insertLastParent(ListParent &lParent, address_parent newParent);

void deleteFirstParent(ListParent &lParent);
void deteleAfterParent(ListParent &lParent, address_parent prec);

void insertFirstChild(ListChild &lChild, address_child newChild);
//void insertLastChild(ListChild &lChild, address_child newchild);
void insertLastChild(address_parent &P, address_child &C);

void deleteFirstChild(ListChild &lChild);
void deleteAfterChild(ListChild &lChild, address_child prec);

void printMLLStructure(ListParent lParent);
void deletelistchild(ListChild &lChild);

void SearchByEkor(ListParent lParent, bool ekor);

#endif
```

### MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(ListParent L){
    return L.firstParent == NULL;
}
bool isEmptyChild(ListChild L){
    return L.firstChild == NULL;
}

void createListParent(ListParent &L){
    L.firstParent = NULL;
    L.lastParent = NULL;
}
void createListChild(ListChild &L){
    L.firstChild = NULL;
    L.lastChild = NULL;
}
address_parent alokasiParent(string idGolongan, string namaGolongan){
    address_parent p = new nodeParent;
    p->isidata.idGolongan = idGolongan;
    p->isidata.namaGolongan = namaGolongan;
    p->nextParent = NULL;
    p->prevParent = NULL;
    p->listChild.firstChild = NULL;
    p->listChild.lastChild = NULL;

    return p;
}
address_child alokasiChild(string idHewan, string namaHewan, string habitat, bool ekor, float bobot){
    address_child p = new nodeChild;
    p->isidata.idHewan = idHewan;
    p->isidata.namaHewan = namaHewan;
    p->isidata.habitat = habitat;
    p->isidata.ekor = ekor;
    p->isidata.bobot = bobot;
    p->nextChild = NULL;
    p->prevChild = NULL;
    return p;
}
void dealokasiParent(address_parent &P){
    P->nextParent = NULL;
    P->prevParent = NULL;
    delete P;
}
void dealokasiChild(address_child &C){
    C->nextChild = NULL;
    C->prevChild = NULL;
    delete C;
}
void insertFirstParent(ListParent &lParent, address_parent newParent){
    if(isEmptyParent(lParent)){
        lParent.firstParent = newParent;
        lParent.lastParent = newParent;
    }else{
        newParent->nextParent = lParent.firstParent;
        lParent.firstParent->prevParent = newParent;
        lParent.firstParent = newParent;
    }
}
void insertLastParent(ListParent &lParent, address_parent newParent){
    if(isEmptyParent(lParent)){
       insertFirstParent(lParent, newParent);
    }else{
        lParent.lastParent->nextParent = newParent;
        newParent->prevParent = lParent.lastParent;
        lParent.lastParent = newParent;
    }
}
void deleteFirstParent(ListParent &lParent){
    address_parent p = lParent.firstParent;
    lParent.firstParent = p->nextParent;
    lParent.firstParent->prevParent = NULL;
    p->nextParent = NULL;
    p->prevParent = NULL;
    dealokasiParent(p);
}
void deteleAfterParent(ListParent &lParent, address_parent prec){
    address_parent p = prec->nextParent;
    prec->nextParent = p->nextParent;
    prec->nextParent->prevParent = prec;
    p->nextParent = NULL;
    p->prevParent = NULL;
    dealokasiParent(p);
}
void insertFirstChild(ListChild &lChild, address_child newChild){
   if(isEmptyChild(lChild)){
       lChild.firstChild = newChild;
       lChild.lastChild = newChild;
   }else{
       newChild->nextChild = lChild.firstChild;
       lChild.firstChild->prevChild = newChild;
       lChild.firstChild = newChild;
   }
}
// void insertLasChild(ListChild &lChild, address_child newchild){
//     if(isEmptyChild(lChild)){
//         insertFirstChild(lChild, newchild);
//     }else{
//         lChild.lastChild->nextChild = newchild;
//         newchild->prevChild = lChild.lastChild;
//         lChild.lastChild = newchild;
//     }
// }

void insertLastChild(address_parent &P, address_child &C){
    if (P == NULL || C == NULL) return;

    ListChild &LC = P->listChild;   

    if (isEmptyChild(LC)) {
        
        LC.firstChild = C;
        LC.lastChild  = C;
        C->nextChild = NULL;
        C->prevChild = NULL;
    } else {
        // tambah di belakang
        LC.lastChild->nextChild = C;
        C->prevChild = LC.lastChild;
        C->nextChild = NULL;
        LC.lastChild = C;
    }
}

void deleteFirstChild(ListChild &lChild){
    address_child p = lChild.firstChild;
    lChild.firstChild = p->nextChild;
    lChild.firstChild->prevChild = NULL;
    p->nextChild = NULL;
    p->prevChild = NULL;
    dealokasiChild(p);
}
void deleteAfterChild(ListChild &lChild, address_child prec){
    address_child p = prec->nextChild;
    prec->nextChild = p->nextChild;
    prec->nextChild->prevChild = prec;
    p->nextChild = NULL;
    p->prevChild = NULL;
    dealokasiChild(p);
}
void printMLLStructure(ListParent lParent){
    if (isEmptyParent(lParent)) {
        cout << "Multi Linked List Kosong!" << endl;
        return;
    }

    cout << "=========== DATA MULTI LINKED LIST ===========\n\n";

    address_parent P = lParent.firstParent;
    int idxParent = 1;

    while (P != NULL) {
        cout << ">>> Parent #" << idxParent << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama        : " << P->isidata.namaGolongan << endl;
        cout << "-------------------------------------------" << endl;

        address_child C = P->listChild.firstChild;

        if (isEmptyChild(P->listChild)) {
            cout << "  (Tidak ada data child)\n\n";
        } else {
            int idxChild = 1;
            while (C != NULL) {
                cout << "  -- Child #" << idxChild << " --\n";
                cout << "  ID Hewan : " << C->isidata.idHewan << endl;
                cout << "  Nama     : " << C->isidata.namaHewan << endl;
                cout << "  Habitat  : " << C->isidata.habitat << endl;
                cout << "  Ekor     : " << (C->isidata.ekor ? "Ya" : "Tidak") << endl;
                cout << "  Bobot    : " << C->isidata.bobot << " kg" << endl;
                cout << "-------------------------------------------" << endl;

                C = C->nextChild;
                idxChild++;
            }
        }

        cout << endl;
        P = P->nextParent;
        idxParent++;
    }

    cout << "===============================================\n";
}


void deletelistchild(ListChild &lChild){
    address_child c = lChild.firstChild;
    address_child temp;

    while( c != NULL){
        temp = c;
        c = c->nextChild;
        dealokasiChild(temp);
    }
    lChild.firstChild = NULL;
}

void SearchByEkor(ListParent lParent, bool ekor){
    address_parent p = lParent.firstParent;
    while(p != NULL){
        address_child c = p->listChild.firstChild;
        while(c != NULL){
            if(c->isidata.ekor == ekor){
                cout << "Data ditemukan pada list anak dari node parent " 
                 << p->isidata.namaGolongan << "!"<< endl; 
                 cout << "Nama Hewan : " << c->isidata.namaHewan << ""<< endl;
            }
            c = c->nextChild;
        }
        p = p->nextParent;
    }
}
```

### Main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main(){
    ListParent p; createListParent(p);
    ListChild c; createListChild(c);

    address_parent P1, P2, P3, P4, P5;
    P1 = alokasiParent( "G001", "Aves"   )    ;
    P2 = alokasiParent( "G002", "Mamalia")    ;
    P3 = alokasiParent( "G003", "Pisces" )    ;
    P4 = alokasiParent( "G004", "Amfibi" )    ;
    P5 = alokasiParent( "G005", "Reptil" )    ;

    insertLastParent(p, P1);
    insertLastParent(p, P2);
    insertLastParent(p, P3);
    insertLastParent(p, P4);
    insertLastParent(p, P5);

    address_child AV1, AV2, M1, M2, M3, AM1;

    // Child nya Aves(P1)
    AV1 = alokasiChild( "AV001", "Cendrawasih", "Hutan", true, 0.3);
    AV2 = alokasiChild( "AV002", "Bebek", "Air", true, 2.0);

    // Child nya Mamalia(P2)
    M1 = alokasiChild( "M001", "Harimau", "Hutan", true, 200.0);
    M2 = alokasiChild( "M002", "Kucing", "Darat", true, 4.0);
    M3 = alokasiChild( "M003", "Gorila", "Hutan", false, 160.0);

    // Child nya Amfibi(P4)
    AM1 = alokasiChild( "AM001", "Kodok", "Sawah", false, 0.2);

    insertLastChild(P1, AV1);
    insertLastChild(P1, AV2);


    insertLastChild(P2, M1);
    insertLastChild(P2, M2);
    insertLastChild(P2, M3);


    insertLastChild(P4, AM1);
    
    printMLLStructure(p);

    cout << "Data hewan yang Punya Ekor : " << endl;
    SearchByEkor(p, true);
    cout << "-------------------------------------" << endl;

    cout << "Data hewan yang tidak ada Ekor : " << endl;
    SearchByEkor(p, false);
    cout << "-------------------------------------" << endl;

    deteleAfterParent(p, P3);
     
    cout << "Data setelah dihapus : " << endl;
    printMLLStructure(p);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan13_Modul13/ScreenshotOutput_Modul13/Output_1.0png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan13_Modul13/ScreenshotOutput_Modul13/Output_1.1png)

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan13_Modul13/ScreenshotOutput_Modul13/Output_2.0png)

##### Output 4
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan13_Modul13/ScreenshotOutput_Modul13/Output_3.0png)

##### Output 5
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan13_Modul13/ScreenshotOutput_Modul13/Output_3.1png)

Kode ini mengimplementasikan struktur data Multi Linked List yang berfungsi untuk mengelola data hewan, di mana setiap Golongan Hewan bertindak sebagai Parent dan detail Hewan di bawahnya bertindak sebagai Child. Parent List ($ListParent$) adalah Doubly Linked List yang menyimpan node $nodeParent$ yang berisi data $golonganHewan$ (ID dan nama golongan) dan memiliki Doubly Linked List internal ($ListChild$) yang berisi data $dataHewan$ (ID, nama, habitat, status ekor, dan bobot). MultiLL.h mendeklarasikan semua struktur data ($golonganHewan$, $dataHewan$, $nodeChild$, $ListChild$, $nodeParent$, $ListParent$) dan prototipe fungsi untuk operasi seperti membuat list ($createListParent$, $createListChild$), alokasi/dealokasi node, serta operasi manipulasi dasar pada list Parent ($insertFirstParent$, $insertLastParent$, $deleteFirstParent$, $deteleAfterParent$) dan Child ($insertFirstChild$, $insertLastChild$, $deleteFirstChild$, $deleteAfterChild$). MultiLL.cpp menyediakan implementasi dari fungsi-fungsi tersebut, termasuk fungsi khusus untuk menampilkan seluruh struktur MLL ($printMLLStructure$) dan mencari hewan berdasarkan status ekor ($SearchByEkor$). Main.cpp berfungsi sebagai driver program, menginisialisasi $ListParent$ dan $ListChild$, membuat beberapa node Parent (Aves, Mamalia, Pisces, Amfibi, Reptil) dan Child (Hewan spesifik), kemudian menyisipkan Child ke Parent yang relevan. Setelah menampilkan seluruh struktur MLL, program mendemonstrasikan fungsi pencarian hewan berekor dan tidak berekor, dan diakhiri dengan menghapus node Parent setelah $P3$ ($deteleAfterParent(p, P3)$), dan menampilkan kembali struktur MLL yang telah diperbarui.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Multi Linked List adalah struktur data yang cukup membantu ketika kita perlu menyimpan data yang bertingkat, seperti data induk yang memiliki banyak data anak. Dengan menggunakan MLL, proses menambah, menghapus, dan menampilkan data jadi lebih teratur dan fleksibel.
Tantangan utamanya ada pada penggunaan pointer, karena kalau salah menghubungkan node bisa membuat data tidak tampil dengan benar. Tetapi setelah memahami alurnya, penerapan MLL terasa lebih mudah dan justru sangat berguna untuk mengelola data secara efisien.
Secara keseluruhan, praktikum ini membantu memperkuat pemahaman tentang pointer serta cara mengelola struktur data yang saling terhubung.

## Referensi
[1] Lafore, R. (2017). Data Structures & Algorithms in C++. Sams Publishing.
<br>[2] Sedgewick, R., & Wayne, K. (2011). Algorithms (4th Edition). Addison-Wesley.
<br>[3] Munir, R. (2019). Algoritma dan Struktur Data. Informatika Bandung.
<br>[4] W. P. Nugroho & A. A. Nugroho. “Penerapan Multi-Linked List pada Sistem Penjadwalan Mata Kuliah.” Jurnal Teknologi Informasi, vol. 12, no. 2, 2019.
<br>[5] Raharjo, B. “Implementasi Struktur Data Linked List pada Aplikasi Manajemen Data Bertingkat.” Jurnal INFOTEL, vol. 10, no. 3, 2018.
<br>[6] G. K. Gupta. (2013). Data Structures and Algorithms in C++. Wiley.
