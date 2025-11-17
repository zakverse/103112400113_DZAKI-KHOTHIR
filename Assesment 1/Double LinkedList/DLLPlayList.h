#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <iostream>
using namespace std;

struct Song{
    string title;
    string artist;
    float duration; // in minutes
    int PlayCount;
    float Rating;
};

typedef Song info;
typedef struct Node* address;

struct Node{
    info data;
    address prev;
    address next;
};

struct List{
    address head;
    address tail;
}; 

bool isEmpty(List L);
void createList(List &L);
address alokasi(string title, string artist, float duration, int PlayCount, float Rating);
void dealokasi(address &P);
void insertFirst(List &L, address P);  
void insertLast(List &L, address P);
void insertAfter(List &L, address Q, address P);
void insertBefore(List &L, address Q, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Q, address &P);
void deleteBefore(List &L, address Q, address &P);
void updateAtPosition(List &L, int position, info newData);
void updateBefore(List &L, address Q, info newData);
void viewList(List L);
void searchByPopularyt(List L , float minRating, float maxRating);




#endif