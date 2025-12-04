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
    
}