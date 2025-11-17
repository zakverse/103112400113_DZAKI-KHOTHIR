#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

int main(){
    StackMahasiswa S ;
    createStack(S);

    Mahasiswa m1 = {"Venti", "1111", 75.7, 82.1, 65.5};
    Mahasiswa m2 = {"Xioa", "2222", 87.4, 88.9, 81.9};
    Mahasiswa m3 = {"Kazuha", "3333", 92.3, 88.8, 82.4};
    Mahasiswa m4 = {"Wanderer", "4444", 95.5, 85.5, 90.5};
    Mahasiswa m5 = {"Lynette", "5555", 77.7, 65.4, 79.9};
    Mahasiswa m6 = {"chasca", "6666", 99.9, 93.6, 87.3};

    push(S, m1);
    push(S, m2);    
    push(S, m3);
    push(S, m4);
    push(S, m5);
    push(S, m6);    

    cout << "Daftar Mahasiswa dalam Stack:" << endl;
    view(S);

    pop(S, m1);
    cout << "Daftar Mahasiswa setelah menghapus: " << endl;        
    view(S);
    update(S , 3 , {"Heizou", "7777", 99.9, 88.8, 77.7});
    view(S);
    searchByNilaiAkhir(S, 85.5, 95.5);

    MaxNilaiAkhir(S, m1.NilaiUAS);
    cout << "Nilai Akhir Tertinggi dalam Stack: " << m1.NilaiUAS << endl;

}