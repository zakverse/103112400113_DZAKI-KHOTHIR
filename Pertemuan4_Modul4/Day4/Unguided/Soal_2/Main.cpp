#include "Singlylist.h"



int main() {
    List L;
    createList(L);

    insertFirst(L, createNode(0));
    insertFirst(L, createNode(2));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(9));
    insertFirst(L, createNode(12));

    cout << "List awal: ";
    printList(L);


    deleteFirst(L);                                                                                                          
    cout << "Setelah deleteFirst: ";
    printList(L);

    
    deleteLast(L);
    cout << "Setelah deleteLast: ";
    printList(L);


    deleteAfter(L.first);
    cout << "Setelah deleteAfter: ";
    printList(L);

    cout << "\nJumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
