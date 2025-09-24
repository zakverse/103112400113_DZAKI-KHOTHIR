#include <iostream>
using namespace std;

string Convert_Angka_Ke_Tulisan(int angka){
    if( angka < 0 || angka > 100 ){
        return "Hanya Bisa Menerima Input 1 - 100 Doang Bro hehe ";
    }

    if( angka == 0 ){
        return "nol";
    }
     
    string satuan[10] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[10] = {"", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[10] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if( angka >= 1 && angka <=9 ){
        return satuan[angka];
    }else if ( angka == 10){
        return puluhan[1];
    }else if ( angka > 10 && angka < 20){
        return belasan[angka - 10];
    }else if ( angka >=20 && angka <= 99 ){
        int AngkaPuluhan = angka / 10;
        int AngkaSatuan = angka % 10;

      string Nama_Final;
      if( AngkaSatuan > 0 ){
        Nama_Final = puluhan[AngkaPuluhan] + " " + satuan[AngkaSatuan];
      }else if (AngkaSatuan == 0){
        Nama_Final = puluhan[AngkaPuluhan];

      }

      return Nama_Final;

    }else if( angka == 100 ){
        return "seratus";

    }

    return " ";
}


int main(){
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << " : " << Convert_Angka_Ke_Tulisan(angka) << endl;

}