#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct Pelajaran{
    string namaMapel ;
    string namaKodeMapel ;

};


Pelajaran create_pelajaran(string namaMapel , string KodePel);

void tampil_pelajaran(Pelajaran pel);

#endif