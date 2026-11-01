#include "stack.h"

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(const Stack &S) {
    return S.Top == nullptr;
}

address alokasi(int x) {
    address p = new Node;
    if (p != nullptr) {
        p->info = x;
        p->next = nullptr;
    }
    return p;
}

void dealokasi(address p) {
    delete p;
}

bool push(Stack &S, int x) {
    address p = alokasi(x);
    if (p == nullptr) {
        std::cout << "[Gagal Push] Alokasi memori gagal!\n";
        return false;
    }
    p->next = S.Top;
    S.Top = p;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        std::cout << "[Gagal Pop] Stack kosong!\n";
        return false;
    }
    address p = S.Top;
    x = p->info;
    S.Top = S.Top->next;
    dealokasi(p);
    return true;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        std::cout << "Stack Kosong\n";
        return;
    }
    std::cout << "TOP: ";
    address p = S.Top;
    while (p != nullptr) {
        std::cout << p->info << " ";
        p = p->next;
    }
    std::cout << "\n";
}

void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);

    int temp;
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, temp);
        push(bantu, temp);
    }

    push(S, x);

    while (!isEmpty(bantu)) {
        pop(bantu, temp);
        push(S, temp);
    }
}

void clearStack(Stack &S) {
    int dummy;
    while (!isEmpty(S)) {
        pop(S, dummy);
    }
}