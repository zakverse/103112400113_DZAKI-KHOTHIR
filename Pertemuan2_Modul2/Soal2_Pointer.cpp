#include <iostream>
using namespace std;


void Tukar(int *x , int *y , int *z){

    int temp ;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;

}

int main(){

    int a = 20 , b = 30 , c = 40;

    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of a : " << &a << endl;
    cout << "Value stored in ptr : " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    Tukar(&a ,&b ,&c);
    cout << "Hasil Tukar a = " << a << " dan B = "<< b << " dan C = " << c <<endl;

}