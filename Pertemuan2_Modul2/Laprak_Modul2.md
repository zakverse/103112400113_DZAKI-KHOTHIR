# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">DZAKI KHOTHIR - 103112400113</p>

## Dasar Teori
Dalam pemrograman C++, terdapat beberapa konsep dasar yang penting untuk dipahami, antara lain pointer, reference, array, prosedur, dan fungsi. Konsep-konsep ini saling berkaitan dalam membangun program yang efisien serta mempermudah proses pemecahan masalah[2].  

### A. Pointer dan Reference  <br/>
Pointer adalah variabel yang digunakan untuk menyimpan alamat memori dari suatu variabel lain. Dengan pointer, programmer dapat mengakses serta memanipulasi data secara langsung melalui alamat memori sehingga lebih fleksibel dalam pengelolaan data [1].  

Reference adalah nama lain (alias) dari suatu variabel. Reference memudahkan pemrograman karena memungkinkan variabel diakses dengan identitas berbeda tanpa harus menggunakan operator khusus seperti pada pointer. Perubahan nilai melalui reference juga akan secara otomatis mempengaruhi variabel asalnya [2].  

Perbedaan utama pointer dan reference adalah pointer dapat diubah untuk menunjuk ke variabel lain, sedangkan reference bersifat tetap pada variabel yang pertama kali diinisialisasi [1][2].  


### B. Array, Prosedur, dan Fungsi  <br/>
Array merupakan struktur data yang menyimpan sekumpulan elemen dengan tipe data yang sama dalam satu blok memori. Elemen-elemen dalam array dapat diakses menggunakan indeks, sehingga mempermudah pengolahan data dalam jumlah banyak [1].  

Prosedur adalah bagian dari program yang digunakan untuk melaksanakan suatu tugas tertentu tanpa menghasilkan nilai balik. Sementara itu, fungsi adalah blok program yang serupa dengan prosedur tetapi menghasilkan nilai balik sebagai hasil eksekusi [2].  

Dengan adanya array, prosedur, dan fungsi, program menjadi lebih terstruktur, mudah dipahami, serta meminimalisasi pengulangan kode.  


## Guided 

### 1. Array
```C++
#include <iostream> 
using namespace std;

int main(){
 int arr[5];

    for( int i = 0 ; i < 5 ; i++ ){

        cout << "Masukkan Value index ke -" << i << " : ";
        cin >> arr[i];

    }

    int j = 0;

    while (j<5){
        cout << "isi index ke-" << j << " : " << arr[j] << endl;
        j++;
    }
}
```
Program ini membuat sebuah array dengan ukuran 5 lalu program mengulang proses dengan for untuk memasukan value dari isi array lalu program menampilkan isi array dengan perulangan while

### 2. Matriks 2x2
```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0;i < 2;i++){
        for (int j = 0 ; j < 2 ; j++)
        cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main(){
   int arrA[2][2] = {
    {1, 2}, // Baris 0
    {3, 4}  // Baris 1
};
int arrB[2][2] = {
    {2, 3}, // Baris 0
    {4, 5}  // Baris 1
};
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matrix 2x2
    for (int i = 0;i<2;i++){
        for (int j = 0; j<2;j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
}

 cout << "Hasil Penjumlahan : " << endl;
        tampilkanHasil(arrC);

//perkalian matrix 2x2
    for (int i = 0;i<2;i++){            //perulangan baris
        for (int j = 0; j<2;j++){       //perulangan kolom
            arrD[i][j] = 0;
            for (int k = 0;k < 2; k++){    //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);
}
```
Program ini melakukan operasi penjumlahan dan perkalian pada matriks berukuran 2x2. Pertama, terdapat fungsi tampilkanHasil yang digunakan untuk mencetak isi matriks ke layar. Dalam program utama, didefinisikan dua matriks awal yaitu arrA dan arrB, kemudian disiapkan arrC untuk menyimpan hasil penjumlahan serta arrD untuk menyimpan hasil perkalian. Proses penjumlahan dilakukan dengan menjumlahkan elemen-elemen yang posisinya sama pada kedua matriks, sedangkan proses perkalian menggunakan tiga lapis perulangan sesuai aturan perkalian matriks, yaitu menjumlahkan hasil kali antara baris pada matriks pertama dengan kolom pada matriks kedua. Setelah perhitungan selesai, program menampilkan hasil penjumlahan dan hasil perkalian matriks ke layar melalui fungsi tampilkanHasil.

### 3. Pointer
```C++
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
```
Program ini menggunakan pointer untuk menukar nilai dua variabel. Pertama, pointer ptr menunjuk ke a sehingga bisa menampilkan alamat dan isi variabel tersebut. Lalu fungsi Tukar dipanggil dengan alamat a dan b, sehingga nilainya saling bertukar, dan hasil akhirnya ditampilkan ke layar.

### 4. Reference
```C++
#include <iostream>
using namespace std;

void Tukar(int &x , int &y){

    int temp ;
    temp = x;
    x = y;
    y = temp;

}

int main(){

    int a = 20 , b = 30;

    int& ref = a;

    cout << "Nilai dari a : " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Value stored in ptr : " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;

    ref = 50;
    cout << "Setelah ref = 50" << endl;
    cout << "Nilai a : " << a << endl;
    cout << "Nilai ref : " << ref << endl;

    Tukar(a ,b);
    cout << "Hasil Tukar a = " << a << " dan B = "<< b <<endl;

}
```
Program ini memakai reference . Reference ref menunjuk ke a, sehingga perubahan pada ref juga mengubah a. Fungsi Tukar menukar nilai a dan b lewat reference, lalu hasilnya ditampilkan.

### 5. Prosedur dan Fungsi
```C++
#include <iostream>
using namespace std;

int carMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1 ; i < ukuran ; i++){
        if(arr[i]> MAX){
            MAX = arr[i];
        }
    }
    return MAX ;
}

void OperasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0 ;
    for(int i = 0 ; i < ukuran ; i++){
        totalJumlah += arr[i];
    }
    cout << "Total Penjumlahan : " << totalJumlah << endl;

    int totalKali = 1 ;
    for (int i = 0 ; i < ukuran ; i++){
        totalKali *= arr[i];
    }
    cout << "Total Perkalian : " << totalKali << endl;
}

int main(){

    const int ukuran = 5 ;
    int arr[ukuran];
    for(int i = 0 ; i < ukuran ; i++){
        cout << "Masukkan Nilai Array  ke-" << i << " : ";
        cin >> arr[i];

    }

    cout << endl;
    cout << "Nilai terbesar dalam array : " << carMAX(arr , ukuran) << endl;

    OperasiAritmatika(arr , ukuran);

    return 0;

}
```
Program ini meminta input 5 angka, lalu mencari nilai terbesar dengan fungsi carMAX. Setelah itu, fungsi OperasiAritmatika menghitung total penjumlahan dan total perkalian semua elemen array, lalu menampilkannya ke layar.

## Unguided 

### 1.  Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3
```C++
#include <iostream>
using namespace std ;

void tampilkanHasil(int arr[3][3]){
    for (int i = 0;i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {1,3,5},
        {2,4,6},
        {7,5,4}
    };
    int arrB[3][3] = {
        {2,3,7},
        {4,5,5},
        {1,3,5}
    };
    int arrC[3][3] = {0}; //jumlah
    int arrD[3][3] = {0}; // kurang
    int arrE[3][3] = {0}; // kali

    //penjumlahan  dan pengurangan matrix 3x3
    for (int i = 0; i < 3 ; i++){
        for (int j = 0 ; j< 3 ; j++){

            arrC[i][j] = arrA[i][j] + arrB[i][j];

            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
 
}

        cout << "Hasil Penjumlahan : " << endl;
        tampilkanHasil(arrC);

        cout << "Hasil Pengurangan : " << endl;
        tampilkanHasil(arrD);

//perkalian matrix 3x3

    for (int i = 0 ; i < 3 ; i++){              //perulangan baris
        for (int j = 0; j < 3 ; j++){           //perulangan kolom
            arrE[i][j] = 0;
            for (int k = 0 ; k < 3 ; k++){      //perulangan perkalian
                arrD[i][j] += arrA[k][j] * arrB[k][j];
            }
        }
    }
    
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);

}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan2_Modul2/ScreenshotOutput_Modul2/Output_Matriks3x3.png)


Program ini mengoprasikan dua matriks 3x3, yaitu arrA dan arrB. Operasi pertama yang dilakukan adalah penjumlahan dan pengurangan elemen-elemen pada posisi yang sama, hasilnya disimpan ke dalam matriks arrC untuk penjumlahan dan arrD untuk pengurangan. Setelah itu, program melakukan perkalian matriks dengan aturan baris dikali kolom, hasilnya dimasukkan ke matriks arrE. Semua hasil perhitungan kemudian ditampilkan ke layar melalui fungsi tampilkanHasil yang mencetak isi matriks dalam bentuk baris dan kolom.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel (Pointer)
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan2_Modul2/ScreenshotOutput_Modul2/Output_Pointer.png)


Program ini bertujuan menukar nilai tiga variabel. Pertama, pointer ptr diarahkan ke a untuk menampilkan nilai, alamat, serta isi yang ditunjuk. Lalu fungsi Tukar dipanggil dengan alamat a, b, dan c, sehingga nilai a dipindahkan ke b, nilai b dipindahkan ke c, dan nilai c dipindahkan ke a.

### 3. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel (Reference)
```C++
#include <iostream>
using namespace std;

void Tukar(int &x , int &y , int &z){

    int temp ;
    temp = x;
    x = y;
    y = z;
    z = temp;
    
}

int main(){

    int a = 20 , b = 30 , c = 40;

    int& ref = a;

    cout << "Nilai dari a : " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Value stored in ptr : " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;

    ref = 50;
    cout << "Setelah ref = 50" << endl;
    cout << "Nilai a : " << a << endl;
    cout << "Nilai ref : " << ref << endl;

    Tukar(a , b , c);
    cout << "Hasil Tukar a = " << a << " dan B = "<< b << " dan C = " << c <<endl;

}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan2_Modul2/ScreenshotOutput_Modul2/Output_Referens.png)

Reference ref dijadikan alias untuk variabel a, sehingga perubahan nilai lewat ref juga mengubah nilai dari a. Lalu Fungsi Tukar yang menerima tiga parameter reference dan menukar nilai a, b, dan c secara bergeser: a mendapat nilai b, b mendapat nilai c, dan c mendapat nilai awal a.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} 
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari 
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan 
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur 
hitungRataRata() untuk menghitung nilai rata – rata!

```C++
#include <iostream> 
using namespace std ;

int cariMinimum(int arr[] , int ukuran){

    int minimum = arr[0]; 
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < minimum){
            minimum = arr[i]; 
        }
    }
    return minimum;
}

int cariMaximum(int arr[] , int ukuran){

    int MAX = arr[0];
    for(int i = 1 ; i < ukuran ; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX ;
}


void hitungRataRata(int arr[] , int ukuran){

    int Awal = 0;
    for( int i = 0 ; i < ukuran  ; i++){
        Awal += arr[i];
    }
    cout << "Rata Rata = " << Awal / ukuran << endl;
}



int main(){
    int input ;
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int panjang = sizeof(arrA) / sizeof(arrA[0]);


    cout << "---  Menu Program Array ---" << endl;
    cout << "1.Tampilkan Isi Array" << endl;
    cout << "2.Cari Nilai Maksimum " << endl;
    cout << "3.Cari Nilai Miminum " << endl;
    cout << "4.Hitung Nilai Rata-Rata " << endl;

    cout << "Masukkan Nilai Menu : ";
    cin >> input ;

    switch (input){

    case 1:
        cout << "Isi Array : " ;
        for( int i = 0 ; i < panjang ; i++){
            cout << arrA[i] << " ";
        }
        break;
    case 2 :
        cout << "Nilai Maksimum Dari Array Adalah : " << cariMaximum(arrA , panjang) << endl;
        break;
    case 3 :
         cout << "Nilai Minimum Dari Array Adalah : " << cariMinimum(arrA , panjang) << endl;
        break;
    case 4 :
        hitungRataRata(arrA , panjang);
        break;

    default:
        cout << "Menu Gak Ada" << endl;
        break;
    }
}
```
### Output Unguided 4 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zakverse/103112400113_DZAKI-KHOTHIR/blob/main/Pertemuan2_Modul2/ScreenshotOutput_Modul2/Output_Menu.png)

Program ini menampilkan menu sederhana untuk melakukan operasi pada array arrA yang berisi 10 elemen. 
Ada empat pilihan: menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung rata-rata elemen array. Fungsi cariMaximum mencari elemen terbesar, cariMinimum mencari elemen terkecil, dan hitungRataRata menjumlahkan semua elemen lalu membagi dengan banyaknya data. Program meminta input menu dari pengguna, lalu menampilkan hasil sesuai pilihan.

## Kesimpulan  

Berdasarkan pembahasan mengenai pointer, reference, array, fungsi, dan prosedur dalam pemrograman C++, dapat disimpulkan bahwa konsep-konsep dasar tersebut sangat penting untuk mendukung efisiensi pengelolaan data. Pointer dan reference memungkinkan pengaksesan data secara langsung melalui alamat memori, sedangkan array mempermudah pengelolaan sekumpulan data dengan tipe yang sama. Fungsi dan prosedur membantu dalam memecah program menjadi bagian-bagian yang lebih sederhana, terstruktur, dan mudah dipelihara.

## Referensi
[1] Universitas Kediri. (2021). *Algoritma & Pemrograman C++*. Universitas Nusantara PGRI Kediri.(https://repository.unpkediri.ac.id/2468/1/55201_0701107802.pdf)  
<br>
[2] Penerbit Widina. (2022). *Belajar Pemrograman Lanjut dengan C++*. Widina.(https://repository.penerbitwidina.com/media/publications/564507-belajar-pemrograman-lanjut-dengan-c-1ac4a1be.pdf)