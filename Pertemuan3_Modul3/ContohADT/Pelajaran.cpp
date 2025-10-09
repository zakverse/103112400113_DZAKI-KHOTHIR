#include "Pelajaran.h"


Pelajaran create_pelajaran(string namaMapel , string KodePel){
    Pelajaran p;
    p.namaMapel = namaMapel;
    p.namaKodeMapel = KodePel;
    return p;
}

void tampil_pelajaran(Pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mapel : " << pel.namaKodeMapel << endl;
}