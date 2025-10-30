#include "DoublyList.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    int n;
    cout << "Berapa banyak data kendaraan yang ingin dimasukkan? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string nopol, warna;
        int tahun;

        cout << "\nMasukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> tahun;
        cin.ignore();

        // cek duplikat nopol
        if (FindElm(L, nopol) != NULL) {
            cout << "Nomor polisi sudah terdaftar!\n";
        } else {
            address P = Alokasi(nopol, warna, tahun);
            Insertlast(L, P);
        }
    }

    cout << "\nDATA LIST 1" << endl;
    PrintInfo(L);

    
    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    getline(cin, cariNopol);

    address hasil = FindElm(L, cariNopol);
    if (hasil != NULL) {
        cout << "\n====================================================" << endl;
        cout << "Nomor Polisi : " << hasil->Info.nopol << endl;
        cout << "Warna        : " << hasil->Info.warna << endl;
        cout << "Tahun        : " << hasil->Info.thnBuat << endl;
        cout << "====================================================" << endl;

    } else {
        cout << "Data tidak ditemukan.\n";
    }

   
    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapusNopol);

    address del = FindElm(L, hapusNopol);
    if (del == NULL) {
        cout << "Data tidak ditemukan.\n";
    } else if (del == L.head) {
        deleteFirst(L, del);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus (FIRST)." << endl;
    } else if (del == L.tail) {
        deleteLast(L, del);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus (LAST)." << endl;
    } else {
        address prec = del->prev;
        deleteAfter(prec, del);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus (AFTER)." << endl;
    }

    cout << "\nDATA LIST 1 setelah penghapusan" << endl;
    PrintInfo(L);

    return 0;
}
