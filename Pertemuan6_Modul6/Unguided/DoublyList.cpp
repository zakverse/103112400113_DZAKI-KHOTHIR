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