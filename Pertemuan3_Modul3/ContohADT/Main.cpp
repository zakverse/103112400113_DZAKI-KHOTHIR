#include <iostream>
#include "Pelajaran.h"
using namespace std;

int main(){

    string Nama_Mapel = "Struktur Data";
    string Kode_Mapel = "STD";

    Pelajaran pel = create_pelajaran(Nama_Mapel , Kode_Mapel);
    tampil_pelajaran(pel);

    return 0;

}