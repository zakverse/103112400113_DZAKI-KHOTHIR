#include <iostream>
using namespace std;

void TampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void TukarIsiArray(int arr1[3][3] , int arr2[3][3], int i , int j){
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void TukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    
    int A[3][3] = { {1,2,3},
                    {4,5,6},
                    {7,8,9} };

    int B[3][3] = { {9,8,7},
                    {6,5,4},
                    {3,2,1} };

    cout << "Array A sebelum ditukar:" << endl;
    TampilArray(A);
    cout << "\nArray B sebelum ditukar:" << endl;
    TampilArray(B);

    int po1 , po2;
    cout << "Posisi di array 1 : ";
    cin >> po1 ;
    cout << "Posisi di array 2 : ";
    cin >> po2 ;

    TukarIsiArray(A, B, po1, po2);

    cout << "\nArray A setelah tukar posisi [" << po1 << "]" << "[" << po2 << "]" << endl;
    TampilArray(A);
     cout << "\nArray B setelah tukar posisi [" << po1 << "]" << "[" << po2 << "]" << endl;
    TampilArray(B);

    int x = 10, y = 99;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    TukarPointer(p1, p2);

    cout << "Setelah tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;


}