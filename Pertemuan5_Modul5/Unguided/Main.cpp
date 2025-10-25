#include <iostream>
#include "ListAngka.h"
using namespace std;

int main(){
    linkedList L;
    CreateList(L);
    address del = NULL;

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);           //  B
    insertLast(L, nodeA);           // B -> A
    insertAfter(L, nodeD, nodeB);  //  B: B -> D -> A
    insertFirst(L, nodeC);        // C -> B -> D -> A
    insertLast(L, nodeE);        // C -> B -> D -> A -> E
    insertFirst(L, nodeF);      // F -> C -> B -> D -> A -> E

    cout <<"=====================" <<endl;
    printList(L);
    cout <<"=====================" <<endl;

    cout<<"\n=================="<<endl;
    delAfter(L, del, nodeC);
    cout<<"=================="<<endl;
    cout << "\n== List setelah operasi insert & delete ==\n";
    printList(L);
    cout << "============================\n" << endl;

    updateFirst(L, 50);
    updateAfter(L, nodeD, 29);
    updateLast(L, 45);
    updateAfter(L, nodeF, 20);

    
    cout << "\n== List setelah update =="<< endl;
    printList(L);
    cout << "============================" << endl;

    cout << "=========Searcing Method=========" << endl ;
    SearchByData(L , 20);
    SearchByData(L , 55);
    SearchByAddress(L,nodeA);
    SearchByRange(L,40);
    cout << "=================================\n" << endl ;


    cout << "Hasil Penjumlahan = " << Tambah(L) << endl;
    cout << "Hasil Pengurangan = " << Kurang(L) << endl;
    cout << "Hasil Perkalian = " << Kali(L) << endl;
    cout << "============================" << endl;

}