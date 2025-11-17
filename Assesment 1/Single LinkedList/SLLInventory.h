#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#include <iostream>
using namespace std;

struct Product{
    string nama;
    string SKU;
    int jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef Product info;
typedef struct Node* address;

struct Node{
    info data;
    address next;
};

struct List{
    address head;
};


bool isEmpty(List L);
void createList(List &L);
address alokasi(string nama , string SKU, int jumlah, float HargaSatuan, float DiskonPersen);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Q, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Q, address &P);
void updateAtposition(List &L, int position, info newData);
void viewlist(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);
void MaxHargaAkhir(List L, float &maxPrice);
#endif