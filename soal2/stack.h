#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Node {
    int info;
    Node* next;
};

typedef Node* address;

struct Stack {
    address Top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
address alokasi(int x);
void dealokasi(address p);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(const Stack &S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif