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