#include <iostream>
using namespace std;

struct Data_Mahasiswa{

    string nama ;
    string nim ;
    float uts ;
    float uas ;
    float tugas;
    float nilai_akhir;

};

float Nilai_Akhir(float uts , float uas , float tugas){

    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas) ;
}


int main(){

    Data_Mahasiswa mhs[10];
    int n ;

    cout << "Masukkan Mahasiswa (Max 10 ) : " ;
    cin >> n;

    for ( int i = 0 ; i < n ; i++ ){
        cout << "Data ke - " << i + 1  << endl;
        cout << "Nama \t: " ;
        cin >> ws;
        getline(cin , mhs[i].nama);
        cout << "NIM \t: " ;
        cin >> mhs[i].nim;
        cout << "Nilai UTS \t: " ;
        cin >> mhs[i].uts;
        cout << "Nilai UAS \t: " ;
        cin >> mhs[i].uas;
        cout << "Nilai TUGAS \t: " ;
        cin >> mhs[i].tugas;

        mhs[i].nilai_akhir = Nilai_Akhir(mhs[i].uts, mhs[i].uas , mhs[i].tugas);
        cout << "Nilai AKHIR \t: " <<mhs[i].nilai_akhir << endl;
    }
cout << endl;
   cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama   : " << mhs[i].nama << endl;
        cout << "NIM    : " << mhs[i].nim << endl;
        cout << "UTS    : " << mhs[i].uts << endl;
        cout << "UAS    : " << mhs[i].uas << endl;
        cout << "Tugas  : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilai_akhir << endl;
        cout << "----------------------------\n";
    }
   
}