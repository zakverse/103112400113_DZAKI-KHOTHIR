#include <iostream>
#include "ListAngka.h"
using namespace std;

int main(){
    linkedList L;
    CreateList(L);

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

    cout << "\n== List setelah operasi insert & delete ==\n";
    printList(L);

    updateFirst(L, 50);
    updateAfter(L, nodeD, 29);
    updateLast(L, 45);
    updateAfter(L, nodeF, 20);

    cout << "\n== List setelah update ==\n";
    printList(L);

}