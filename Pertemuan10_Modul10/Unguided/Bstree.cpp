#include "Bstree.h"
#include <iostream>
using namespace std;

address alokasi(int x){
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL; 
    return p;
}
void insertNode(address &root , int x){
    if (root == NULL){
        root = alokasi(x);
    } else if (x < root->info){
        insertNode(root->left , x);
    } else if (x > root->info){
        insertNode(root->right , x);
    }
}
address findNode(int x, address root){
    if (root == NULL){
        return NULL;
    } else if (x == root->info){
        return root;
    } else if (x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}
void inOrder(address root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->info << " - ";
        inOrder (root->right);
    }
}

//2
int hitungJumlahNode(address root){
    if (root == NULL){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}
int hitungTotalInfo(address root, int start){
    if (root == NULL){
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}
int hitungKedalaman(address root, int start){
    if (root == NULL){
        return -1;
    } else {
        int kiri = hitungKedalaman(root->left, start);
        int kanan = hitungKedalaman(root->right, start);
        int kedalaman;
        if (kiri > kanan){
            kedalaman = kiri;
        } else {
            kedalaman = kanan;
        }
        return kedalaman + 1;   
    }
    cout << endl;
}


//3
void preOrder(address root){
    if ( root != NULL){
        cout << root->info << " - ";
        preOrder (root->left);
        preOrder (root->right);
    }
}
void postOrder(address root){
    if ( root != NULL){
        postOrder (root->left);
        postOrder (root->right);
        cout << root->info << " - ";
    }
}

void reverseInOrder(address root){
    if (root != NULL){
        reverseInOrder(root->right);
        cout << root->info << " - ";
        reverseInOrder(root->left);
    }
}