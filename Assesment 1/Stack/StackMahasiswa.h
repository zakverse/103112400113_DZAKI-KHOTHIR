#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa{
    Mahasiswa info[MAX];
    int top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void push(StackMahasiswa &S, Mahasiswa data);
void pop(StackMahasiswa &S, Mahasiswa &data);
void update(StackMahasiswa &S, int position, Mahasiswa newData);
void view(StackMahasiswa S);
void searchByNilaiAkhir(StackMahasiswa S, float minNilai, float maxNilai);
void MaxNilaiAkhir(StackMahasiswa S, float &maxNilai);


#endif