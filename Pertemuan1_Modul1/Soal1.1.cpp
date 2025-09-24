#include <iostream>
using namespace std;


int main() {
    float bilangan1, bilangan2;

    cout << "Masukkan bilangan pertama \t: ";
    cin >> bilangan1;

    cout << "Masukkan bilangan kedua \t: ";
    cin >> bilangan2;

    float penjumlahan = bilangan1 + bilangan2;
    float pengurangan = bilangan1 - bilangan2;
    float perkalian = bilangan1 * bilangan2;
    float pembagian = bilangan1 / bilangan2;

    cout << "Hasil penjumlahan: " << penjumlahan << endl;
    cout << "Hasil pengurangan: " << pengurangan << endl;
    cout << "Hasil perkalian: " << perkalian << endl;
    cout << "Hasil pembagian: " << pembagian << endl;

}