#include <iostream>
using namespace std;

struct Pelajaran{
    string namaMapel ;
    string namaKodeMapel ;

};

Pelajaran create_pelajaran(string namaMapel , string KodePel){
    Pelajaran p;
    p.namaMapel = namaMapel;
    p.namaKodeMapel = KodePel;
    return p;
}

void tampil_pelajaran(Pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.namaKodeMapel << endl;
}

int main(){

    string Nama_Mapel = "Struktur Data";
    string Kode_Mapel = "STD";

    Pelajaran pel = create_pelajaran(Nama_Mapel , Kode_Mapel);
    tampil_pelajaran(pel);

    return 0;

}