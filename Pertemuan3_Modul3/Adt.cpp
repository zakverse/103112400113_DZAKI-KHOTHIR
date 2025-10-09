#include <iostream>
using namespace std;

struct MahaSigma{
   string nama;
   float nilai1 , nilai2;


};

void InputMahaSigma( MahaSigma &m ){

    cout << "NAMA : " ;
    cin >> m.nama;
    cout << "NILAI 1 : ";
    cin >> m.nilai1;
    cout << "NILAI 2 : ";
    cin >> m.nilai2;
}

float Rata_Rata(MahaSigma m){

    return((m.nilai1 + m.nilai2) / 2 );
}


int main(){
    MahaSigma mhs ;
    InputMahaSigma(mhs);
    cout << "rata rata : " << " " << Rata_Rata(mhs) << endl;

}