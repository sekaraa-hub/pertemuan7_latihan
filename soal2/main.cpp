#include <iostream>
#include "stack.h"

void jalankanPengujian(Stack &S) {
    std::cout << "\n--- Menjalankan Skenario Pengujian Otomatis ---\n";
    clearStack(S);

    pushAscending(S, 3);
    pushAscending(S, 7);
    pushAscending(S, 2);
    pushAscending(S, 7);
    pushAscending(S, 5);
    std::cout << "Sesudah memasukkan 3, 7, 2, 7, 5:\n";
    printInfo(S);


    int val;
    if (pop(S, val)) {
        std::cout << "Sesudah satu Pop (nilai keluar = " << val << "):\n";
        printInfo(S);
    }
    pushAscending(S, 6);
    std::cout << "Sesudah memasukkan 6:\n";
    printInfo(S);

    std::cout << "\n-- Uji Tambahan --\n";
    Stack S2;
    createStack(S2);
    pushAscending(S2, -2);
    pushAscending(S2, 0);
    pushAscending(S2, -2);
    std::cout << "Hasil TOP (-2, 0, -2): ";
    printInfo(S2);

    while (pop(S2, val)) {
        std::cout << "Pop nilai: " << val << "\n";
    }

    pop(S2, val);

    clearStack(S2);
    std::cout << "-----------------------------------------------\n\n";
}

int main() {
    Stack S;
    createStack(S);
    int pilihan, val;

    do {
        std::cout << "\n=== MENU STACK LINKED LIST (ASCENDING) ===\n";
        std::cout << "1. Tambah Terurut (pushAscending)\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Tampilkan (printInfo)\n";
        std::cout << "4. Jalankan Tes Skenario Soal\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan angka: ";
                std::cin >> val;
                pushAscending(S, val);
                std::cout << "Berhasil menambahkan " << val << " secara terurut.\n";
                break;
            case 2:
                if (pop(S, val)) {
                    std::cout << "Nilai yang di-Pop: " << val << "\n";
                }
                break;
            case 3:
                printInfo(S);
                break;
            case 4:
                jalankanPengujian(S);
                break;
            case 5:
                clearStack(S);
                std::cout << "Stack dibersihkan. Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}