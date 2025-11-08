#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

const int MAX = 20;

struct Stack{
   int info[MAX];
   int top;
};

bool is_Empty(Stack s);
bool is_Full(Stack s);
void CreateStack(Stack &s);
void push(Stack &s , int x);
void pop(Stack &s);
int popValue(Stack &s);
void printInfo(Stack s);
void balikStack(Stack &s);
void pushAscending(Stack &s , int x);
void getInputStream(Stack &s);


#endif