#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(const Stack &S) {
    return S.Top == 0;
}

bool isFull(const Stack &S) {
    return S.Top == 20;
}

bool push(Stack &S, int x) {
    if (isFull(S)) {
        std::cout << "[Gagal Push] Stack penuh! Elemen " << x << " ditolak.\n";
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        std::cout << "[Gagal Pop] Stack kosong!\n";
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        std::cout << "Stack Kosong\n";
        return;
    }
    std::cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        std::cout << S.info[i] << " ";
    }
    std::cout << "\n";
}

void balikStack(Stack &S) {
    if (isEmpty(S)) return;

    Stack bantu1, bantu2;
    createStack(bantu1);
    createStack(bantu2);

    int val;
    while (!isEmpty(S)) {
        pop(S, val);
        push(bantu1, val);
    }
    while (!isEmpty(bantu1)) {
        pop(bantu1, val);
        push(bantu2, val);
    }
    while (!isEmpty(bantu2)) {
        pop(bantu2, val);
        push(S, val);
    }
}