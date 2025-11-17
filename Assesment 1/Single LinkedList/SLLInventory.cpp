#include "SLLInventory.h"
#include <iostream>
using namespace std;    

bool isEmpty(List L){
    return L.head == NULL;
}
void createList(List &L){
    L.head = NULL;
}
address alokasi(string nama , string SKU, int jumlah, float HargaSatuan, float DiskonPersen){
    address P = new Node;
    P->data.nama = nama;
    P->data.SKU = SKU;
    P->data.jumlah = jumlah;
    P->data.HargaSatuan = HargaSatuan;
    P->data.DiskonPersen = DiskonPersen;
    P->next = NULL;
    return P;
}
void dealokasi(address &P){
    P->next = NULL;
    delete P;
}
void insertFirst(List &L, address P){
    P->next = L.head;
    L.head = P;
}
void insertLast(List &L, address P){
    if (isEmpty(L)){
        insertFirst(L, P);
    }else{
        address Q = L.head;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertAfter(List &L, address Q, address P){
    if (Q != NULL && P != NULL){
        P->next = Q->next;
        Q->next = P;
    }
}
void deleteFirst(List &L, address &P){
    if (!isEmpty(L)){
        P = L.head;
        L.head = L.head->next;
        P->next = NULL;
        dealokasi(P);
    }
}
void deleteLast(List &L, address &P){
    if( !isEmpty(L)){
        if (L.head->next == NULL){
            deleteFirst(L, P);
        }else{
            address Q = L.head;
            while (Q->next->next != NULL){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
            dealokasi(P);
        }
    }
}
void deleteAfter(List &L, address Q, address &P){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        if (Q != NULL && Q->next != NULL){
            P = Q->next;
            Q->next = P->next;
            P->next = NULL;
            dealokasi(P);
        }
    }
}
void updateAtposition(List &L, int position, info newData){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        address P = L.head;
        int idx = 0;
        while (P != NULL && idx < position){
            P = P->next;
            idx++;
        }
        if (P != NULL){
            P->data = newData;
        }else{
            cout << "Posisi tidak valid" << endl;
        }
    }
}
void viewlist(List L){
    address P = L.head;
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        while (P != NULL){
            cout << "Nama Produk: " << P->data.nama << endl;
            cout << "SKU: " << P->data.SKU << endl;
            cout << "Jumlah: " << P->data.jumlah << endl;
            cout << "Harga Satuan: " << P->data.HargaSatuan << endl;
            cout << "Diskon Persen: " << P->data.DiskonPersen << "%" << endl;
            float finalPrice = P->data.HargaSatuan * (1 - P->data.DiskonPersen / 100);
            cout << "Harga Akhir setelah Diskon: " << finalPrice << endl;
            cout << "------------------------" << endl;
            P = P->next;
        }
    }
}
void searchByFinalPriceRange(List L, float minPrice, float maxPrice){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        address P = L.head;
        bool found = false;
        while (P != NULL){
            float finalPrice = P->data.HargaSatuan * (1 - P->data.DiskonPersen / 100);
            if (finalPrice >= minPrice && finalPrice <= maxPrice){
                cout << "Nama Produk: " << P->data.nama << endl;
                cout << "SKU: " << P->data.SKU << endl;
                cout << "Jumlah: " << P->data.jumlah << endl;
                cout << "Harga Satuan: " << P->data.HargaSatuan << endl;
                cout << "Diskon Persen: " << P->data.DiskonPersen << "%" << endl;
                cout << "Harga Akhir setelah Diskon: " << finalPrice << endl;
                cout << "------------------------" << endl;
                found = true;
            }
            P = P->next;
        }   
        if (!found){
            cout << "Tidak di temukan" << endl;
        }

    }
}

void MaxHargaAkhir(List L, float &maxPrice){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
        maxPrice = 0;
    }else{
        address p = L.head;
        maxPrice = p->data.HargaSatuan * (1 - p->data.DiskonPersen / 100);
        p = p->next;
        while (p != NULL){
            float finalPrice = p->data.HargaSatuan * (1 - p->data.DiskonPersen / 100);
            if (finalPrice > maxPrice){
                maxPrice = finalPrice;
            }
            p = p->next;
        }
    }
}
