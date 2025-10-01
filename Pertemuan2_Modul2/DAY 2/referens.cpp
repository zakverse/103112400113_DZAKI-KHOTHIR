#include <iostream>
using namespace std;

void Tukar(int &x , int &y){

    int temp ;
    temp = x;
    x = y;
    y = temp;

}

int main(){

    int a = 20 , b = 30;

    int& ref = a;

    cout << "Nilai dari a : " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Value stored in ptr : " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;

    ref = 50;
    cout << "Setelah ref = 50" << endl;
    cout << "Nilai a : " << a << endl;
    cout << "Nilai ref : " << ref << endl;

    Tukar(a ,b);
    cout << "Hasil Tukar a = " << a << " dan B = "<< b <<endl;

}