#include "ListAngka.h"

void CreateList(linkedList &L){
    L.first = NULL ;
}

bool IsEmpty(linkedList L){
    return L.first == NULL;
}

address alokasi(dataAngka x){
    address p = new Node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address p){
    delete p;
    p = NULL;
}

void printList(linkedList L){
    address p = L.first;
    cout << "Isi Dari List :" << endl;
    if(IsEmpty(L)){
        cout << "Data Kosong " << endl;
    }else{
        while(p != NULL){
            cout << p->angka;
            if (p->next != NULL) {cout << " -> ";}
            p = p->next;
        }
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p){
    if(IsEmpty(L)){
        L.first = p ;
        p->next = NULL;
    }else{
        p->next = L.first;
        L.first = p;
    }
}

void insertLast(linkedList &L, address p){
    if (IsEmpty(L)){
        insertFirst(L , p);
    }else{
       address current = L.first;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = p;
        }
}

void insertAfter(linkedList &L, address p, address prec){
    p->next = prec->next;
    prec->next = p;
}

//nbList itu Count 
int nbList(linkedList L){
    if(IsEmpty(L)){
        cout << "List Kosong" << endl ;
        return 0;
    }else{
        int count = 0;
        address current = L.first;  
        while(current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }
}

void delAfter(linkedList &L, address &p, address prec){
    if(IsEmpty(L)){
        cout << "Data Kosong" << endl;
        p = NULL;
    }else if (prec == NULL || prec->next == NULL){
        cout << "Tidak Ada Next nya" << endl;
        p = NULL;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
        cout << "Node setelah " << prec->angka << " berhasil dihapus." << endl;
    }
}

void updateFirst(linkedList &L , dataAngka newVal){
    if (!IsEmpty(L))
        L.first->angka = newVal;
}

void updateLast(linkedList &L , dataAngka newVal){
    if (IsEmpty(L)) return;
    address current = L.first;
    while(current->next != NULL){
        current = current->next;
    }
    current->angka = newVal;
}

void updateAfter(linkedList &L, address prec , dataAngka newVal){
   if (prec != NULL && prec->next != NULL)
        prec->next->angka = newVal;
}

void SearchByData(linkedList L, int data){
    address current = L.first;
    bool found = false ;
    while (current != NULL){
        if(current->angka == data){
        cout << "Data " << data << " ditemukan di alamat " << current << endl;
        found = true;
    }
    current = current->next;
    }

    if (!found){ cout << "Data " << data << " tidak ditemukan." << endl;}
}

void SearchByAddress(linkedList L, address node){
    address current = L.first;
    bool found = false;
    while(current != NULL){
        if(current == node){
            cout << "Alamat " << node << " ditemukan dengan nilai " << current->angka << endl;
            found = true;
            break;
        }
        current = current->next;
    }
    if(!found){
        cout << "Alamat " << node << " tidak ditemukan di list.\n";
    }
}

void SearchByRange(linkedList L, int nilaiMin){
    address current = L.first;
    bool found = false;
    cout << "Data dengan nilai >= " << nilaiMin << ":\n";
    while(current != NULL){
        if(current->angka >= nilaiMin){
            cout << "  " << current->angka << " (alamat " << current << ")\n";
            found = true;
        }
        current = current->next;
    }
    if(!found){
        cout << "Tidak ada data di atas " << nilaiMin << endl;
    }
}


int Tambah(linkedList L){
    int total = 0;
    address current = L.first;
    while(current != NULL){
        total = total + current->angka;
        current = current->next;
    }
    return total;
}

int Kurang(linkedList L){
    int total = 0;
    address current = L.first;
    while(current != NULL){
        total = total - current->angka;
        current = current->next;
    }
    return total;
}

int Kali(linkedList L){
    int total = 1;
    address current = L.first;
    while(current != NULL){
        total = total * current->angka;
        current = current->next;
    }
    return total;
}