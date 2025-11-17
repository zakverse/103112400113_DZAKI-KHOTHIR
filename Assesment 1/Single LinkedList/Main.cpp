#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main(){
    List inventory ;
    createList(inventory);
    //Product newData;
    
    address A = alokasi("Pulpen", "A001", 20, 2500.0, 0.0);
    address B = alokasi("Buku Tulis", "A002", 15, 5000.0, 10.0);
    address C = alokasi("Penghapus", "A003", 30, 1500.0, 0.0);

    insertLast(inventory, A);
    insertLast(inventory, B);
    insertLast(inventory, C);

    cout << "Daftar Inventory Produk:" << endl;
    viewlist(inventory);

    deleteFirst(inventory, A);

    cout << "Daftar Inventory Produk setelah menghapus produk pertama:" << endl;
    viewlist(inventory);

    updateAtposition(inventory , 2 , {"Stabilo", "A010", 40, 9000.0, 5.0});
    cout << "Daftar Inventory Produk setelah memperbarui produk pada posisi 2:" << endl;
    viewlist(inventory);

    searchByFinalPriceRange(inventory, 2000.0, 7000.0);

    MaxHargaAkhir(inventory, A->data.HargaSatuan);
    cout << "Harga Akhir Tertinggi dalam Inventory: " << A->data.HargaSatuan << endl;
}   
