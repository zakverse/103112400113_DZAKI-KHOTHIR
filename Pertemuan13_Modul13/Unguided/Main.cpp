#include "MultiLL.h"
#include <iostream>
using namespace std;

int main(){
    ListParent p; createListParent(p);
    ListChild c; createListChild(c);

    address_parent P1, P2, P3, P4, P5;
    P1 = alokasiParent( "G001", "Aves"   )    ;
    P2 = alokasiParent( "G002", "Mamalia")    ;
    P3 = alokasiParent( "G003", "Pisces" )    ;
    P4 = alokasiParent( "G004", "Amfibi" )    ;
    P5 = alokasiParent( "G005", "Reptil" )    ;

    insertLastParent(p, P1);
    insertLastParent(p, P2);
    insertLastParent(p, P3);
    insertLastParent(p, P4);
    insertLastParent(p, P5);

    address_child AV1, AV2, M1, M2, M3, AM1;

    // Child nya Aves(P1)
    AV1 = alokasiChild( "AV001", "Cendrawasih", "Hutan", true, 0.3);
    AV2 = alokasiChild( "AV002", "Bebek", "Air", true, 2.0);

    // Child nya Mamalia(P2)
    M1 = alokasiChild( "M001", "Harimau", "Hutan", true, 200.0);
    M2 = alokasiChild( "M002", "Kucing", "Darat", true, 4.0);
    M3 = alokasiChild( "M003", "Gorila", "Hutan", false, 160.0);

    // Child nya Amfibi(P4)
    AM1 = alokasiChild( "AM001", "Kodok", "Sawah", false, 0.2);

    insertLastChild(P1, AV1);
    insertLastChild(P1, AV2);


    insertLastChild(P2, M1);
    insertLastChild(P2, M2);
    insertLastChild(P2, M3);


    insertLastChild(P4, AM1);
    
    printMLLStructure(p);

    cout << "Data hewan yang Punya Ekor : " << endl;
    SearchByEkor(p, true);
    cout << "-------------------------------------" << endl;

    cout << "Data hewan yang tidak ada Ekor : " << endl;
    SearchByEkor(p, false);
    cout << "-------------------------------------" << endl;

    deteleAfterParent(p, P3);
     
    cout << "Data setelah dihapus : " << endl;
    printMLLStructure(p);
    return 0;
}