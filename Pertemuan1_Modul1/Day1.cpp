#include <iostream>
#include <string>
using namespace std;

void Tambah(int angka1 , int angka2){
    cout << "Tambah = "<< angka1 + angka2 << endl;
}

void Kurang(int angka1 , int angka2){
    cout << "Kurang = "<< angka1 - angka2 << endl;
}

void Bagi(int angka1 , int angka2){
      cout << "Bagi = "<< angka1 / angka2 << endl;
}

void Kali(int angka1 , int angka2){
    cout << "Kali = "<< angka1 * angka2 << endl;
}

void BandingAngka(int angka1 , int angka2){

    if( angka1 > angka2){
        cout << angka1 << " Lebih Besar dari " << angka2 << endl;
    }else if( angka1 < angka2 ){
        cout << angka1 << " Lebih Kecil dari " << angka2 << endl;
    }else{
        cout << "Bro Ini angka nya sama" << endl;
    }
}

void Whilelop(){
     //While Loop
    int i = 0 ;
    int j = 10;
    while(i < 10){
        cout << i << " - ";
        i++;
    }

    do{
        cout << j << " - ";
        j++;

    }while( j < 10 );

}

const int jumlah = 5 ;


struct rapot {
    char nama[5];
    int nilai;
};

int main(){
    

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama : ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai : ";
        cin >> siswa[i].nilai;
    }

     cout << "\n--- Data Siswa ---\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama: " << siswa[i].nama 
             << ", Nilai: " << siswa[i].nilai << endl;
    }

   
}