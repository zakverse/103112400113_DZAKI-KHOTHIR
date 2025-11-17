#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    while (true) {   
        cout << "\n--- Komiya Ekspress ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. View Data Paket" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            Paket p;
            cout << "Masukkan Kode Resi: ";
            cin >> p.KodeResi;
            cout << "Masukkan Nama Pengirim: ";
            cin >> p.NamaPengirim;
            cout << "Masukkan Berat Barang (kg): ";
            cin >> p.BeratBarang;
            cout << "Masukkan Tujuan: ";
            cin >> p.Tujuan;

            enqueue(Q, p);
            break;
        }

        case 2: {
            Paket p = dequeue(Q);
            if (!p.KodeResi.empty()) {
                cout << "Paket dengan Kode Resi " << p.KodeResi 
                     << " telah dihapus dari queue." << endl;
            }
            break;
        }

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Keluar dari program." << endl;
            cout << "Total biaya pengiriman: ";
            TotalBiayaPengiriman(Q, 8250);
            return 0;       

        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }
}
