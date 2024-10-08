#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string generateKey(string text, string key) {
    int x = text.size();
    string newKey = key;
    for (int i = key.size(); i < x; i++) {
        newKey += key[i % key.size()];
    }
    return newKey;
}

string encryptVigenere(string text, string key) {
    string cipher_text = "";
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char x = (text[i] - base + (toupper(key[i]) - 'A')) % 26 + base;
            cipher_text.push_back(x);
        } else {
            cipher_text.push_back(text[i]);
        }
    }
    return cipher_text;
}

string decryptVigenere(string cipher_text, string key) {
    string original_text = "";
    for (int i = 0; i < cipher_text.size(); i++) {
        if (isalpha(cipher_text[i])) {
            char base = isupper(cipher_text[i]) ? 'A' : 'a';
            char x = (cipher_text[i] - base - (toupper(key[i]) - 'A') + 26) % 26 + base;
            original_text.push_back(x);
        } else {
            original_text.push_back(cipher_text[i]);
        }
    }
    return original_text;
}

void processFromFile(string filename, bool isEncrypt) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "File tidak ditemukan!" << endl;
        return;
    }

    string text, key;
    getline(inputFile, text);
    cout << "Masukkan kunci: ";
    cin >> key;

    string extendedKey = generateKey(text, key);
    string result = isEncrypt ? encryptVigenere(text, extendedKey) : decryptVigenere(text, extendedKey);
    
    cout << "Hasil: " << result << endl;
}

void processFromInput(bool isEncrypt) {
    string text, key;
    cout << "Masukkan teks: ";
    cin.ignore(); 
    getline(cin, text);
    cout << "Masukkan kunci: ";
    cin >> key;

    string extendedKey = generateKey(text, key);
    string result = isEncrypt ? encryptVigenere(text, extendedKey) : decryptVigenere(text, extendedKey);

    cout << "Hasil: " << result << endl;
}

int main() {
    int pilihan;
    cout << "Vigenere Cipher\n";
    cout << "1. Enkripsi\n";
    cout << "2. Dekripsi\n";
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> pilihan;

    int inputMethod;
    cout << "Pilih metode input:\n";
    cout << "1. Input langsung\n";
    cout << "2. Input dari file\n";
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> inputMethod;

    if (inputMethod == 1) {
        processFromInput(pilihan == 1);
    } else if (inputMethod == 2) {
        string filename;
        cout << "Masukkan nama file: ";
        cin >> filename;
        processFromFile(filename, pilihan == 1);
    } else {
        cout << "Pilihan metode input tidak valid!" << endl;
    }

    return 0;
}
