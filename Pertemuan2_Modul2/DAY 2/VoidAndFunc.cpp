#include <iostream>
using namespace std;

int carMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1 ; i < ukuran ; i++){
        if(arr[i]> MAX){
            MAX = arr[i];
        }
    }
    return MAX ;
}

void OperasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0 ;
    for(int i = 0 ; i < ukuran ; i++){
        totalJumlah += arr[i];
    }
    cout << "Total Penjumlahan : " << totalJumlah << endl;

    int totalKali = 1 ;
    for (int i = 0 ; i < ukuran ; i++){
        totalKali *= arr[i];
    }
    cout << "Total Perkalian : " << totalKali << endl;
}

int main(){

    const int ukuran = 5 ;
    int arr[ukuran];
    for(int i = 0 ; i < ukuran ; i++){
        cout << "Masukkan Nilai Array  ke-" << i << " : ";
        cin >> arr[i];

    }

    cout << endl;
    cout << "Nilai terbesar dalam array : " << carMAX(arr , ukuran) << endl;

    OperasiAritmatika(arr , ukuran);

    return 0;

}