#include <iostream>
#include "stack.h"

void jalankanPengujian(Stack &S) {
    std::cout << "\n--- Menjalankan Skenario Pengujian Otomatis ---\n";
    int val;
    push(S, 7);
    push(S, 12);
    push(S, 5);
    if (pop(S, val)) std::cout << "Berhasil Pop: " << val << "\n";
    push(S, 9);
    push(S, 3);
    if (pop(S, val)) std::cout << "Berhasil Pop: " << val << "\n";
    push(S, 15);

    std::cout << "Kondisi Setelah Operasi:\n";
    printInfo(S);

    balikStack(S);
    std::cout << "Kondisi Setelah balikStack:\n";
    printInfo(S);
    std::cout << "-----------------------------------------------\n\n";
}

int main() {
    Stack S;
    createStack(S);
    int pilihan, val;

    do {
        std::cout << "\n=== MENU STACK ARRAY ===\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Tampilkan (printInfo)\n";
        std::cout << "4. Balik Stack\n";
        std::cout << "5. Jalankan Tes Skenario Soal\n";
        std::cout << "6. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan angka: ";
                std::cin >> val;
                if (push(S, val)) {
                    std::cout << "Berhasil menambahkan " << val << " ke stack.\n";
                }
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
                balikStack(S);
                std::cout << "Stack berhasil dibalik.\n";
                printInfo(S);
                break;
            case 5:
                jalankanPengujian(S);
                break;
            case 6:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}