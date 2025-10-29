#include "DoublyList.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    CreateList(L);

    address P1 = Alokasi("B1234AA", "Merah", 2010);
    address P2 = Alokasi("D5678BB", "Hitam", 2015);
    address P3 = Alokasi("E9999CC", "Putih", 2020);

    Insertlast(L, P1);
    Insertlast(L, P2);
    Insertlast(L, P3);

    cout << "\n== Setelah Insert ==" << endl;
    PrintInfo(L);

    address cari = FindElm(L, "D5678BB");
    if (cari != NULL)
        cout << "\nData ditemukan: " << cari->Info.nopol << " - " << cari->Info.warna << endl;

    deleteFirst(L, P1);
    cout << "\n== Setelah deleteFirst ==" << endl;
    PrintInfo(L);

    deleteLast(L, P3);
    cout << "\n== Setelah deleteLast ==" << endl;
    PrintInfo(L);

    cari = FindElm(L, "D5678BB");
    if (cari != NULL)
        deleteAfter(cari, P2);

    cout << "\n== Setelah deleteAfter ==" << endl;
    PrintInfo(L);

}