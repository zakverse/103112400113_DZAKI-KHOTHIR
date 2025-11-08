#include"Stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &s){
    s.top = -1;
}

bool is_Empty(Stack s){
    return (s.top == -1);
}

bool is_Full(Stack s){
    return (s.top == MAX - 1) ;
}

void push(Stack &s , int x){
    if (is_Full(s)){
        cout << "Stack Penuh!" << endl;
    }else{
        s.top++;
        s.info[s.top] = x;
    }
}

void pop(Stack &s){
    if(is_Empty(s)){
        cout << "Stack Kosong" <<endl;
    }else{
        s.top--;
    }
}
int popValue(Stack &s){
    if (is_Empty(s)){
        cout << "Stack Kosong" << endl;
        return -1;
    }else{
     int x = s.info[s.top];
     s.top--;
     return x;
    }
}

void printInfo(Stack s){
    cout << "[TOP] ";
    for (int i = s.top ; i >= 0 ; i--){
        cout << s.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &s){
    Stack temp ;
    CreateStack(temp);
    while(!is_Empty(s)){
        push(temp , popValue(s));
    }
    s = temp;
   
}

void pushAscending(Stack &s, int x) {
    if (is_Full(s)) {
        cout << "Stack penuh!\n";
        return;
    }

    Stack temp;
    CreateStack(temp);

    while (!is_Empty(s) && s.info[s.top] > x) {
        push(temp, popValue(s));
    }

    push(s, x);

    while (!is_Empty(temp)) {
        push(s, popValue(temp));
    }
}

void getInputStream(Stack &s) {
    char c;
    cout << "Masukkan angka (akhiri dengan Enter): ";
    while (cin.get(c) && c != '\n') {
        if (isdigit(c)) {
            push(s, c - '0');
        }
    }
}
