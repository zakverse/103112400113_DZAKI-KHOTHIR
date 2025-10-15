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

    return 0;
}
