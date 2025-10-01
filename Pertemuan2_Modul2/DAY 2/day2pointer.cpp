#include <iostream>
using namespace std;


void Tukar(int *x , int *y){

    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;

}

int main(){

    int a = 20 , b = 30;

    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of a : " << &a << endl;
    cout << "Value stored in ptr : " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    Tukar(&a ,&b);
    cout << "Hasil Tukar a = " << a << " dan B = "<< b <<endl;

}