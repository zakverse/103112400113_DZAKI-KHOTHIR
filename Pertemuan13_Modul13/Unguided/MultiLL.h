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