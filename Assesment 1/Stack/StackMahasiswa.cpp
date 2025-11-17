#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa S){
    return S.top == -1;
}
bool isFull(StackMahasiswa S){
    return S.top == MAX - 1;
}
void createStack(StackMahasiswa &S){
    S.top = -1;
}
void push(StackMahasiswa &S, Mahasiswa data){ 
    if(!isFull(S)){
        S.top++;
        S.info[S.top] = data;
    }else{
        cout << "Stack penuh!" << endl;
    }
}
void pop(StackMahasiswa &S, Mahasiswa &data){
    if(!isEmpty(S)){
        data = S.info[S.top];
        S.top--;
    }else{
        cout << "Stack kosong!" << endl;
    }
}
void update(StackMahasiswa &S, int position, Mahasiswa newData){
    if(isEmpty(S)){
        cout << "Stack Kosong " << endl;
    }else{
        if(position >=0 && position <= S.top){
            S.info[position] = newData;
        }else{
            cout << "Posisi tidak valid" << endl;
        }
    }
}
void view(StackMahasiswa S){
    if(isEmpty(S)){
        cout << "Stack Kosong " << endl;
    }else{
        for(int i = S.top ; i >= 0 ; i--){
            cout << "Nama: " << S.info[i].nama << endl;
            cout << "NIM: " << S.info[i].NIM << endl;
            cout << "Nilai Tugas: " << S.info[i].NilaiTugas << endl;
            cout << "Nilai UAS: " << S.info[i].NilaiUAS << endl;
            float nilaiAkhir = 0.4 * S.info[i].NilaiTugas + 0.6 * S.info[i].NilaiUAS;
            cout << "Nilai Akhir: " << nilaiAkhir << endl;
            cout << "------------------------" << endl;
        }
    }
}
void searchByNilaiAkhir(StackMahasiswa S, float minNilai, float maxNilai){
    if(isEmpty(S)){
        cout << "Stack Kosong " << endl;
    }else{
        bool found = false;
        for(int i = 0 ; i <= S.top ; i++){
            float nilaiAkhir = 0.2 * S.info[i].NilaiTugas + 0.4 * S.info[i].NilaiUTS + 0.4 * S.info[i].NilaiUAS;
            if(nilaiAkhir >= minNilai && nilaiAkhir <= maxNilai){
                cout << "Nama: " << S.info[i].nama << endl;
                cout << "NIM: " << S.info[i].NIM << endl;
                cout << "Nilai Tugas: " << S.info[i].NilaiTugas << endl;
                cout << "Nilai UAS: " << S.info[i].NilaiUAS << endl;
                cout << "Nilai Akhir: " << nilaiAkhir << endl;
                cout << "------------------------" << endl;
                found = true;
            }
        }
        if(!found){
            cout << "Tidak ada mahasiswa dengan nilai akhir dalam rentang tersebut." << endl;
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa S, float &maxNilai){
    if(isEmpty(S)){
        cout << "Stack Kosong " << endl;
    }else{
        maxNilai = -1; 
        for(int i = 0 ; i <= S.top ; i++){
            float nilaiAkhir = 0.2 * S.info[i].NilaiTugas + 0.4 * S.info[i].NilaiUTS + 0.4 * S.info[i].NilaiUAS;
            if(nilaiAkhir > maxNilai){
                maxNilai = nilaiAkhir;
            }
        }
    }
}