#include"Stack.h"
#include <iostream>
using namespace std;

int main(){
cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);




    cout << "\n\nHello world!" << endl;
    Stack AS;
    CreateStack(AS);
    pushAscending(AS, 3);
    pushAscending(AS, 4);
    pushAscending(AS, 8);
    pushAscending(AS, 2);
    pushAscending(AS, 3);
    pushAscending(AS, 9);
    printInfo(AS);

    cout << "balik stack" << endl;
    balikStack(AS);
    printInfo(AS);
    

    cout << "\n\nHello world!" << endl;
    Stack IS;
    CreateStack(IS);
    getInputStream(IS);
    printInfo(IS);

    cout << "balik stack" << endl;
    balikStack(IS);
    printInfo(IS);

}

