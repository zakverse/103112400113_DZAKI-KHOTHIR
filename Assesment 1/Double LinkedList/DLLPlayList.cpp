#include "DLLPlayList.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    return L.head == NULL && L.tail == NULL;
}
void createList(List &L){
    L.head = NULL;
    L.tail = NULL;
}
address alokasi(string title, string artist, float duration, int PlayCount, float Rating){
    address P = new Node;
    P->data.title = title;
    P->data.artist = artist;    
    P->data.duration = duration;
    P->data.PlayCount = PlayCount;
    P->data.Rating = Rating;
    P->prev = NULL;
    P->next = NULL;
    return P;
}
void dealokasi(address &P){
    P->prev = NULL;
    P->next = NULL;
    delete P;
}
void insertFirst(List &L, address P){
    if (isEmpty(L)){
        L.head = P;
        L.tail = P;
    }else{
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}
void insertLast(List &L, address P){
    if (isEmpty(L)){
        L.head = P;
        L.tail = P;
    }else{
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}
void insertAfter(List &L, address Q, address P){
    if(isEmpty(L) || Q == NULL){
        cout << "List Kosong atau Node Q NULL" << endl;
    }else{
        if(Q == L.tail){
            insertLast(L, P);
        }else{
            P->next = Q->next;
            P->prev = Q;
            Q->next->prev = P;
            Q->next = P;
        }
    }
}
void insertBefore(List &L, address Q, address P){
    if(isEmpty(L) || Q == NULL){
        cout << "List Kosong" << endl;
    }else{
        if(Q == L.head){
            insertFirst(L, P);
        }else{
            P->prev = Q->prev;
            P->next = Q;
            Q->prev->next = P;
            Q->prev = P;
        }
    }
}
void deleteFirst(List &L, address &P){
    if(isEmpty(L)){
        cout << "List Kosong" << endl;
    }else{
        P = L.head;
        if(L.head == L.tail){
            L.head = NULL;
            L.tail = NULL;
        }else{
            L.head = L.head->next;
            L.head->prev = NULL;
            P->next = NULL;
        }
        dealokasi(P);
    }
}
void deleteLast(List &L, address &P){
    if(isEmpty(L)){
        cout << "List Kosong" << endl;
    }else{
        P = L.tail;
        if(L.head == L.tail){
            L.head = NULL;
            L.tail = NULL;
        }else{
            L.tail = L.tail->prev;
            L.tail->next = NULL;
            P->prev = NULL;
        }
        dealokasi(P);
    }
}
void deleteAfter(List &L, address Q, address &P){
    if(isEmpty(L)){
        cout << "List Kosong" << endl;
    }else{
        if(Q != NULL && Q->next != NULL){
            P = Q->next;
            Q->next = P->next;
            if(P->next != NULL){
                P->next->prev = Q;
            }else{
                L.tail = Q;
            }
            P->prev = NULL;
            P->next = NULL;
            dealokasi(P);
        }
    }
}
void deleteBefore(List &L, address Q, address &P){
    if (isEmpty(L)){
        cout << "List Kosong" << endl;  
    } else{
        if (Q != NULL && Q->prev != NULL){
            P = Q->prev;
            Q->prev = P->prev;
            if (P->prev != NULL){
                P->prev->next = Q;
            } else {
                L.head = Q;
            }
            P->prev = NULL;
            P->next = NULL;
            dealokasi(P);
        }
    }
}
void updateAtPosition(List &L, int position, info newData){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        address P = L.head;
        int idx = 0;
        while (P != NULL && idx < position){
            P = P->next;
            idx++;
        }
        if (P != NULL){
            P->data = newData;
        }else{
            cout << "Posisi engga ada" << endl;
        }
    }
}
void updateBefore(List &L, address Q, info newData){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        if (Q != NULL && Q->prev != NULL){
            address P = Q->prev;
            P->data = newData;
        }else{
            cout << "engga bisa update" << endl;
        }
    }
}
void viewList(List L){
    address P = L.head;
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        while (P != NULL){
            cout << "Title: " << P->data.title << endl;
            cout << "Artist: " << P->data.artist << endl;
            cout << "Duration: " << P->data.duration << " minutes" << endl;
            cout << "PlayCount: " << P->data.PlayCount << endl;
            cout << "Rating: " << P->data.Rating << endl;
            cout << "------------------------" << endl;
            P = P->next;
        }
    }   
}
void searchByPopularyt(List L , float minRating, float maxRating){
    if (isEmpty(L)){
        cout << "List Kosong " << endl;
    }else{
        address P = L.head;
        bool found = false;
        while (P != NULL){
            if (P->data.Rating >= minRating && P->data.Rating <= maxRating){
                cout << "Title: " << P->data.title << endl;
                cout << "Artist: " << P->data.artist << endl;
                cout << "Duration: " << P->data.duration << " minutes" << endl;
                cout << "PlayCount: " << P->data.PlayCount << endl;
                cout << "Rating: " << P->data.Rating << endl;
                cout << "------------------------" << endl;
                found = true;
            }
            P = P->next;
        }   
        if (!found){
            cout << "Tidak di temukan" << endl;
        }

    }
}
