#include "DLLPlayList.h"
#include <iostream>
using namespace std;

int main(){
    List lagu ;
    createList(lagu);

    address a = alokasi("Senja Di Kota","NonaBand", 210.0, 150, 4.2);
    address b = alokasi("Langkahmu", "Delta", 185.0, 320, 4.8);
    address c = alokasi("Hujan Minggu", "Arka", 240.0, 90, 3.9);

    insertLast(lagu, a);
    insertLast(lagu, b);    
    insertLast(lagu, c);
    cout << "Daftar Lagu dalam Playlist:" << endl;
    viewList(lagu);
    deleteFirst(lagu, a);
    cout << "Daftar Lagu setelah menghapus lagu pertama:" << endl;
    viewList(lagu);
    updateAtPosition(lagu , 1 , {"Pelita", "Luna", 200.0, 260, 4.5});
    cout << "Daftar Lagu setelah memperbarui lagu:" << endl;
    viewList(lagu);

    insertBefore(lagu, c, alokasi("Senandung" , "Mira", 175, 120, 4.0));
    cout << "Daftar Lagu setelah menyisipkan lagu sebelum lagu kedua:" << endl;
    viewList(lagu);
    
    updateBefore(lagu, c, {"Cahaya", "Rina", 220.0, 300, 4.7});
    cout << "Daftar Lagu setelah memperbarui lagu sebelum lagu ketiga:" << endl;
    viewList(lagu);

    updateBefore(lagu, b, {"Mentari", "Sari", 190.0, 180, 4.3});
    cout << "Daftar Lagu setelah memperbarui lagu sebelum lagu kedua:" << endl;
    viewList(lagu);

    searchByPopularyt(lagu, 150.0, 300.0);
}