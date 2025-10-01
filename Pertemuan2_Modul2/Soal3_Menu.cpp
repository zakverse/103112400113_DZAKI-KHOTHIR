#include <iostream> 
using namespace std ;

int cariMinimum(int arr[] , int ukuran){

    int minimum = arr[0]; 
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < minimum){
            minimum = arr[i]; 
        }
    }
    return minimum;
}

int cariMaximum(int arr[] , int ukuran){

    int MAX = arr[0];
    for(int i = 1 ; i < ukuran ; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX ;
}


void hitungRataRata(int arr[] , int ukuran){

    int Awal = 0;
    for( int i = 0 ; i < ukuran  ; i++){
        Awal += arr[i];
    }
    cout << "Rata Rata = " << Awal / ukuran << endl;
}



int main(){
    int input ;
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int panjang = sizeof(arrA) / sizeof(arrA[0]);


    cout << "---  Menu Program Array ---" << endl;
    cout << "1.Tampilkan Isi Array" << endl;
    cout << "2.Cari Nilai Maksimum " << endl;
    cout << "3.Cari Nilai Miminum " << endl;
    cout << "4.Hitung Nilai Rata-Rata " << endl;

    cout << "Masukkan Nilai Menu : ";
    cin >> input ;

    switch (input){

    case 1:
        cout << "Isi Array : " ;
        for( int i = 0 ; i < panjang ; i++){
            cout << arrA[i] << " ";
        }
        break;
    case 2 :
        cout << "Nilai Maksimum Dari Array Adalah : " << cariMaximum(arrA , panjang) << endl;
        break;
    case 3 :
         cout << "Nilai Minimum Dari Array Adalah : " << cariMinimum(arrA , panjang) << endl;
        break;
    case 4 :
        hitungRataRata(arrA , panjang);
        break;

    default:
        cout << "Menu Gak Ada" << endl;
        break;
    }
}