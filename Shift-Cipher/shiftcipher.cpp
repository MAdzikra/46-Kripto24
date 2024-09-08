#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + shift - 65) % 26 + 65);
        } else if (islower(text[i])) {
            result += char(int(text[i] + shift - 97) % 26 + 97);
        } else {
            result += text[i];
        }
    }

    return result;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    int pilihan, shift;
    string text;

    do {
        cout << "Menu:\n";
        cout << "1. Enkripsi\n";
        cout << "2. Dekripsi\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
            cout << "Masukkan pergeseran (shift): ";
            cin >> shift;
            cin.ignore();
            cout << "Masukkan teks: ";
            getline(cin, text);

            if (pilihan == 1) {
                cout << "Teks terenkripsi: " << encrypt(text, shift) << endl << endl;
            } else if (pilihan == 2) {
                cout << "Teks terdekripsi: " << decrypt(text, shift) << endl << endl;
            }
        }

    } while (pilihan != 3);

    return 0;
}
