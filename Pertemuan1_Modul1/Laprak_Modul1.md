# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Bahasa C++ merupakan pengembangan dari bahasa C yang mendukung paradigma pemrograman prosedural dan berorientasi objek. C++ banyak digunakan dalam pembelajaran struktur data karena fleksibel, cepat, dan memiliki dukungan pustaka standar yang luas [1]. IDE (Integrated Development Environment) seperti CodeBlocks dan Visual Studio Code membantu mahasiswa untuk menulis, menjalankan, dan melakukan debugging program dengan lebih mudah [2].

Konsep dasar dalam C++ meliputi input dan output menggunakan cin dan cout, operator aritmatika seperti +, -, *, dan / untuk perhitungan, fungsi untuk modularisasi kode, serta percabangan dengan if-else untuk pengambilan keputusan. Selain itu, perulangan (for, while, do-while) mempermudah proses iterasi, sedangkan array dan struct memungkinkan penyimpanan banyak data sekaligus [3].

### A. CodeBlocks IDE <br/>

CodeBlocks adalah IDE open-source yang mendukung bahasa C, C++, dan Fortran. 
IDE ini menyediakan fitur compiler bawaan, debugging, serta interface yang sederhana untuk pemula.

#### 1. Instalasi CodeBlocks
#### 2. Membuat Project Baru
#### 3. Menjalankan Program

### B. Bahasa C++ <br/>

Bahasa C++ adalah pengembangan dari bahasa C yang memiliki fitur tambahan seperti Object Oriented Programming (OOP).

#### 1. Struktur dasar program C++
#### 2. Input & Output
#### 3. Operator Aritmatika

## Guided 

### 1. Program Dasar C++(Input Output , If-Else , Perulangan , Fungsi , Prosedur , Array , Struct)

```C++
#include <iostream>
#include <string>
using namespace std;

void Tambah(int angka1 , int angka2){
    cout << "Tambah = "<< angka1 + angka2 << endl;
}

void Kurang(int angka1 , int angka2){
    cout << "Kurang = "<< angka1 - angka2 << endl;
}

void Bagi(int angka1 , int angka2){
      cout << "Bagi = "<< angka1 / angka2 << endl;
}

void Kali(int angka1 , int angka2){
    cout << "Kali = "<< angka1 * angka2 << endl;
}
void BandingAngka(int angka1 , int angka2){

    if( angka1 > angka2){
        cout << angka1 << " Lebih Besar dari " << angka2 << endl;
    }else if( angka1 < angka2 ){
        cout << angka1 << " Lebih Kecil dari " << angka2 << endl;
    }else{
        cout << "Bro Ini angka nya sama" << endl;
    }
}

void Whilelop(){
     //While Loop
    int i = 0 ;
    int j = 10;
    while(i < 10){
        cout << i << " - ";
        i++;
    }

    do{
        cout << j << " - ";
        j++;

    }while( j < 10 );

}

const int jumlah = 5 ;


struct rapot {
    char nama[5];
    int nilai;
};

int main(){
    

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama : ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai : ";
        cin >> siswa[i].nilai;
    }

     cout << "\n--- Data Siswa ---\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama: " << siswa[i].nama 
             << ", Nilai: " << siswa[i].nilai << endl;
    }

   
}
```
penjelasan singkat guided 1

Pada program ini meimplementasikan beberapa dasar dari bahasa pemrograman C++, antara lain:

Input dan Output
Menggunakan cin untuk membaca data dari pengguna dan cout untuk menampilkan hasil ke layar.

Fungsi
Program dibagi menjadi beberapa fungsi seperti Tambah, Kurang, Kali, Bagi, dan BandingAngka. Hal ini bertujuan agar kode lebih terstruktur, modular, dan mudah dipanggil ulang.

Operator Matematika
Operator aritmatika seperti +, -, *, dan / digunakan untuk melakukan operasi perhitungan dasar.

Percabangan
Menggunakan struktur if-else untuk membuat keputusan, misalnya pada fungsi BandingAngka untuk membandingkan dua bilangan.

Perulangan
Program menggunakan for loop, while loop dan do-while loop untuk menampilkan nama siswa dan nilai.

Array dan Struct
Digunakan struct rapot untuk menyimpan data siswa berupa nama dan nilai dalam bentuk array, sehingga dapat menampung lebih dari satu data sekaligus.


## Unguided 

### 1. Soal Unguided 1

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan1_Modul1/Screenshot_Output/Output_Soal1.1.png)


Program ini Mengoperasikan dua angka bertipe data float yang di inputkan oleh user dan dua angka tersebut akan di jumlahkan , kurangkan, dibagikan dan dikalikan, lalu program akan memberikan output hasil operasi nya

### 2. Soal Unguided 2

```C++
#include <iostream>
using namespace std;

string Convert_Angka_Ke_Tulisan(int angka){
    if( angka < 0 || angka > 100 ){
        return "Hanya Bisa Menerima Input 1 - 100 Doang Bro hehe ";
    }

    if( angka == 0 ){
        return "nol";
    }
     
    string satuan[10] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[10] = {"", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[10] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if( angka >= 1 && angka <=9 ){
        return satuan[angka];
    }else if ( angka == 10){
        return puluhan[1];
    }else if ( angka > 10 && angka < 20){
        return belasan[angka - 10];
    }else if ( angka >=20 && angka <= 99 ){
        int AngkaPuluhan = angka / 10;
        int AngkaSatuan = angka % 10;

      string Nama_Final;
      if( AngkaSatuan > 0 ){
        Nama_Final = puluhan[AngkaPuluhan] + " " + satuan[AngkaSatuan];
      }else if (AngkaSatuan == 0){
        Nama_Final = puluhan[AngkaPuluhan];

      }

      return Nama_Final;

    }else if( angka == 100 ){
        return "seratus";

    }

    return " ";
}


int main(){
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << " : " << Convert_Angka_Ke_Tulisan(angka) << endl;

}
```
### Output Unguided 2 :

![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan1_Modul1/Screenshot_Output/Output_Soal1.2.png)


Program ini bertujuan mengonversi angka menjadi tulisan dalam bahasa Indonesia dengan rentang 0–100, menggunakan fungsi Convert_Angka_Ke_Tulisan yang memanfaatkan array satuan, belasan, dan puluhan sebagai acuan kata logika percabangan if-else digunakan untuk membedakan kasus angka satuan, belasan, puluhan, hingga seratus

### 3. Soal Unguided 3

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan1_Modul1/Screenshot_Output/Output_Soal1.3.png)


Program yang kamu buat ini menghasilkan pola angka simetris dengan tanda bintang (*) di tengah berdasarkan batas yang dimasukkan pengguna. Cara kerjanya adalah: pertama program meminta input batas, lalu menggunakan dua lapis perulangan for untuk mencetak spasi di awal baris, deret angka menurun, simbol *, dan deret angka menaik sehingga terbentuk pola segitiga terbalik yang rapi; setelah seluruh baris dicetak, terdapat tambahan kondisi if (batas > 0) untuk mencetak bintang terakhir di bagian bawah sebagai penutup pola.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa pemrograman dasar C++ melatih pemahaman tentang struktur program, penggunaan input-output, operator aritmatika, fungsi, percabangan, perulangan, hingga array dan struct, serta logika dalam membangun pola; melalui implementasi berbagai contoh program seperti kalkulator sederhana, konversi angka ke tulisan, dan pencetakan pola, dan bagaimana sintaks C++ digunakan.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara.
[2] Indahyati, Uce., & Rahmawati, Yunianita. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
[3] Laksono, A. D., & Saputra, R. (2021). Implementasi Struktur Data dan Algoritma dengan Bahasa C++. Jurnal Teknologi Informasi, 12(2), 45–52.
<br>...
