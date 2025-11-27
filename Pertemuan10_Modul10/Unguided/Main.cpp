#include "Bstree.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World!" << endl;
    address root = NULL;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    
    inOrder(root);

    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root, 0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;   

    cout<<"\n";
    cout << "Pre Order : ";
    preOrder(root);
    cout << "\nPost Order : ";
    postOrder(root);
    cout << endl;
    cout << "Reverse In Order : ";
    reverseInOrder(root);
    cout << endl;


    return 0;
}