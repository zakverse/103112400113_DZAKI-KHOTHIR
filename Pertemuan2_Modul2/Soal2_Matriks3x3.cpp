#include <iostream>
using namespace std ;


void tampilkanHasil(int arr[3][3]){
    for (int i = 0;i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {1,3,5},
        {2,4,6},
        {7,5,4}
    };
    int arrB[3][3] = {
        {2,3,7},
        {4,5,5},
        {1,3,5}
    };
    int arrC[3][3] = {0}; //jumlah
    int arrD[3][3] = {0}; // kurang
    int arrE[3][3] = {0}; // kali

    //penjumlahan  dan pengurangan matrix 3x3
    for (int i = 0; i < 3 ; i++){
        for (int j = 0 ; j< 3 ; j++){

            arrC[i][j] = arrA[i][j] + arrB[i][j];

            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
 
}

        cout << "Hasil Penjumlahan : " << endl;
        tampilkanHasil(arrC);

        cout << "Hasil Pengurangan : " << endl;
        tampilkanHasil(arrD);

//perkalian matrix 3x3

    for (int i = 0 ; i < 3 ; i++){              //perulangan baris
        for (int j = 0; j < 3 ; j++){           //perulangan kolom
            arrE[i][j] = 0;
            for (int k = 0 ; k < 3 ; k++){      //perulangan perkalian
                arrD[i][j] += arrA[k][j] * arrB[k][j];
            }
        }
    }
    
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);

}