#include <iostream>
using namespace std;

int main(){

    int batas;
    cout << "Masukkan Batas \t: ";
    cin >> batas;

    for( int i = batas ; i >= 1 ; i-- ){
        for( int j = 0 ; j < batas - i ; j++ ){
            cout << " ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << "*";

        for (int j = 1; j <= i ; j++) {
            cout << j;
        }

        cout << endl;
    }

        if ( batas > 0) {
       
        for (int j = 0; j < batas ; ++j) {
            cout << " ";
        }
        cout << "*" << endl;
    }

    
}