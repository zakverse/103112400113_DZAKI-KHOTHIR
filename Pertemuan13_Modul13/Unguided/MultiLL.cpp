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
void insertLasChild(ListChild &lChild, address_child newchild){
    if(isEmptyChild(lChild)){
        insertFirstChild(lChild, newchild);
    }else{
        lChild.lastChild->nextChild = newchild;
        newchild->prevChild = lChild.lastChild;
        lChild.lastChild = newchild;
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
    if(isEmptyParent(lParent)){
        cout << "Multi Linked List Kosong!" << endl;
        return;
    }

    address_parent p = lParent.firstParent;
    int posisiParent = 1;

    while(p != NULL){
        cout << "Data ditemukan pada list anak dari node parent " 
             << p->isidata.namaGolongan
             << " pada posisi ke-" << posisiParent << "!" << endl;

        
        address_child c = p->listChild.firstChild;
        int posisiChild = 1;

        if(isEmptyChild(p->listChild)){
            cout << "--- Data Child ---" << endl;
            cout << "Tidak ada data child." << endl;
            cout << "------------------------------" << endl;
        } else {
            while(c != NULL){
                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << c->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posisiChild << endl;
                cout << "Nama Hewan : " << c->isidata.namaHewan << endl;
                cout << "Habitat : " << c->isidata.habitat << endl;
                cout << "Ekor : " << (c->isidata.ekor ? "1" : "0") << endl;
                cout << "Bobot : " << c->isidata.bobot << endl;
                cout << "------------------------------" << endl;

                c = c->nextChild;
                posisiChild++;
            }
        }

        cout << "--- Data Parent ---" << endl;
        cout << "ID Parent : " << p->isidata.idGolongan << endl;
        cout << "Posisi dalam list induk : posisi ke-" << posisiParent << endl;
        cout << "Nama golongan : " << p->isidata.namaGolongan << endl;
        cout << "------------------------------------------------" << endl;

        p = p->nextParent;
        posisiParent++;
    }
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