# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE  (ADT) </h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematika dari objek data yang menyempurnakan tipe data dengan mengaitkannya dengan fungsi-fungsi yang beroperasi pada data tersebut [1]. Secara informal, ADT merupakan konsep pemrograman yang mendefinisikan tipe data baru beserta operasi-operasinya [2].

### A. Definisi dan Tujuan ADT <br/>
ADT didefinisikan sebagai sekumpulan data dan operasi terhadap data tersebut yang definisinya tidak bergantung pada implementasi tertentu [3]. Dengan kata lain, definisi ADT hanya menunjukkan operasi apa yang akan dilakukan, tetapi tidak menunjukkan bagaimana operasi tersebut diimplementasikan [2]

## Guided 

### 1. Input Mahasiswa

```C++
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
```
Program ini menerapkan ADT MahaSigma menggunakan struct. prosedur InputMahaSigma berisi teks dan penginputan dari user  yang menggunakan call-by-reference (ditandai dengan & pada parameter) untuk mengubah data anggota objek mhs. Fungsi Rata_Rata adalah operasi yang menghitung rata-rata dengan perhitungan nilai1 + nilai2 lalu dibagi 2

### 2. ADT Pelajaran

### Pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct Pelajaran{
    string namaMapel ;
    string namaKodeMapel ;

};


Pelajaran create_pelajaran(string namaMapel , string KodePel);

void tampil_pelajaran(Pelajaran pel);

#endif
```

### Pelajaran.cpp
```C++
#include "Pelajaran.h"


Pelajaran create_pelajaran(string namaMapel , string KodePel){
    Pelajaran p;
    p.namaMapel = namaMapel;
    p.namaKodeMapel = KodePel;
    return p;
}

void tampil_pelajaran(Pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mapel : " << pel.namaKodeMapel << endl;
}
```

### Main.cpp
```C++
    #include <iostream>
#include "Pelajaran.h"
using namespace std;

int main(){

    string Nama_Mapel = "Struktur Data";
    string Kode_Mapel = "STD";

    Pelajaran pel = create_pelajaran(Nama_Mapel , Kode_Mapel);
    tampil_pelajaran(pel);

    return 0;
}
```
Pelajaran.h berisi spesifikasi ADT (struktur data dan deklarasi fungsi), sementara Pelajaran.cpp berisi implementasi operasi . Main.cpp  memanggil fungsi fungsi yang telah di buat lalu sekaligus untuk tempat run kode untuk melihat output.

## Unguided 

### 1. Soal 1

```C++
#include <iostream>
using namespace std;

struct Data_Mahasiswa{

    string nama ;
    string nim ;
    float uts ;
    float uas ;
    float tugas;
    float nilai_akhir;

};

float Nilai_Akhir(float uts , float uas , float tugas){

    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas) ;
}


int main(){

    Data_Mahasiswa mhs[10];
    int n ;

    cout << "Masukkan Mahasiswa (Max 10 ) : " ;
    cin >> n;

    for ( int i = 0 ; i < n ; i++ ){
        cout << "Data ke - " << i + 1  << endl;
        cout << "Nama \t: " ;
        cin >> ws;
        getline(cin , mhs[i].nama);
        cout << "NIM \t: " ;
        cin >> mhs[i].nim;
        cout << "Nilai UTS \t: " ;
        cin >> mhs[i].uts;
        cout << "Nilai UAS \t: " ;
        cin >> mhs[i].uas;
        cout << "Nilai TUGAS \t: " ;
        cin >> mhs[i].tugas;

        mhs[i].nilai_akhir = Nilai_Akhir(mhs[i].uts, mhs[i].uas , mhs[i].tugas);
        cout << "Nilai AKHIR \t: " <<mhs[i].nilai_akhir << endl;
    }
cout << endl;
   cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama   : " << mhs[i].nama << endl;
        cout << "NIM    : " << mhs[i].nim << endl;
        cout << "UTS    : " << mhs[i].uts << endl;
        cout << "UAS    : " << mhs[i].uas << endl;
        cout << "Tugas  : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilai_akhir << endl;
        cout << "----------------------------\n";
    }
   
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan3_Modul3/ScreenshotOutput_Modul3/Output_DataMahasiswa.png)

Program mendefinisikan struct yang berisi nama, nim , uts ,uas , tugas , nilai akhir. Fungsi Nilai_Alhir Berfungsi menghitung nilai akhir dengan parameter uts , uas , dan tugas. Lalu di main user di beri arahan untuk mengisi data dengan max yaitu 7 dan user menginput data data mahasiswa. dan terakhir program menampilkan hasil yang sudah user inuputkan

### 2. Soal 2

### Pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct Pelajaran{
    string namaMapel ;
    string namaKodeMapel ;
};


Pelajaran create_pelajaran(string namaMapel , string KodePel);

void tampil_pelajaran(Pelajaran pel);

#endif
```

### Pelajaran.cpp
```C++
#include "Pelajaran.h"

Pelajaran create_pelajaran(string namaMapel , string KodePel){
    Pelajaran p;
    p.namaMapel = namaMapel;
    p.namaKodeMapel = KodePel;
    return p;
}

void tampil_pelajaran(Pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mapel : " << pel.namaKodeMapel << endl;
}
```

### Main.cpp
```C++
    #include <iostream>
#include "Pelajaran.h"
using namespace std;

int main(){

    string Nama_Mapel = "Struktur Data";
    string Kode_Mapel = "STD";

    Pelajaran pel = create_pelajaran(Nama_Mapel , Kode_Mapel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan3_Modul3/ScreenshotOutput_Modul3/Output_Pelajaran.png)

Pelajaran.h berisi spesifikasi ADT (struktur data dan deklarasi fungsi), sementara Pelajaran.cpp berisi implementasi operasi . Main.cpp  memanggil fungsi fungsi yang telah di buat lalu sekaligus untuk tempat run kode untuk melihat output.

### 3. Soal 3

```C++
#include <iostream>
using namespace std;
void TampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void TukarIsiArray(int arr1[3][3] , int arr2[3][3], int i , int j){
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}
void TukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(){
    int A[3][3] = { {1,2,3},
                    {4,5,6},
                    {7,8,9} };
    int B[3][3] = { {9,8,7},
                    {6,5,4},
                    {3,2,1} };
    cout << "Array A sebelum ditukar:" << endl;
    TampilArray(A);
    cout << "\nArray B sebelum ditukar:" << endl;
    TampilArray(B);
    int po1 , po2;
    cout << "Posisi di array 1 : ";
    cin >> po1 ;
    cout << "Posisi di array 2 : ";
    cin >> po2 ;
    TukarIsiArray(A, B, po1, po2);

    cout << "\nArray A setelah tukar posisi [" << po1 << "]" << "[" << po2 << "]" << endl;
    TampilArray(A);
     cout << "\nArray B setelah tukar posisi [" << po1 << "]" << "[" << po2 << "]" << endl;
    TampilArray(B);

    int x = 10, y = 99;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    TukarPointer(p1, p2);

    cout << "Setelah tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;


}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan3_Modul3/ScreenshotOutput_Modul3/Output_Tukar.png)

Fungsi TukarIsiArray menukar berdasarkan inpur user mau menukar di baris dan kolom berapa . Lalu Fungsi TukarPointer secara eksplisit menggunakan pointer untuk menerapkan call-by-reference dengan menukar nilai yang ditunjuk (*p1 dan *p2). 


## Kesimpulan
Abstract Data Type (ADT) adalah konsep penting yang memisahkan spesifikasi (interface) dari implementasi (internal details) data dan operasi, berlandaskan prinsip Abstraksi dan Enkapsulasi [2, 3]. Pemisahan ini, yang diimplementasikan secara formal menggunakan class di C++, memungkinkan client menggunakan tipe data tanpa perlu tahu bagaimana data disimpan atau operasinya dilakukan. Praktikum ini menunjukkan implementasi dasar ADT menggunakan struct dan fungsi-fungsi terpisah, serta menggarisbawahi pentingnya pointer dan call-by-reference sebagai mekanisme fundamental untuk membangun dan memanipulasi representasi internal ADT secara efisien.

## Referensi
[1] UIN Sumatera Utara. "Struktur Data - Tipe Data Abstrak (ADT)". Repository UIN Sumatera Utara. (URL: http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf)
<br>
[2] Nugraha, Muhammad Rizky (2023). "Makalah Abstrak Data Type". Makalah/Dokumen Akademik. (URL: https://id.scribd.com/document/683914578/Makalah-Abstrak-Data-Type)
<br>
[3] Budiman, Saiful Nur. "Abstract Data Type". Presentasi Akademik. (URL: https://id.scribd.com/presentation/457093469/03-Abstract-Data-Type-pptx)
<br>
