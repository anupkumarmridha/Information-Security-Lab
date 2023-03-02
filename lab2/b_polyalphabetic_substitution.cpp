#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(string message, string key) {
    string ciphertext = "";
    int j = 0;
    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext += 'A' + ((message[i] - 'A') + (key[j % key.length()] - 'A')) % 26;
            } else {
                ciphertext += 'a' + ((message[i] - 'a') + (key[j % key.length()] - 'a')) % 26;
            }
            j++;
        } else if (isdigit(message[i])) {
            ciphertext += '0' + ((message[i] - '0') + (key[j % key.length()] - '0')) % 10;
            j++;
        } else {
            ciphertext += message[i];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string message = "";
    int j = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                message += 'A' + ((ciphertext[i] - 'A') - (key[j % key.length()] - 'A') + 26) % 26;
            } else {
                message += 'a' + ((ciphertext[i] - 'a') - (key[j % key.length()] - 'a') + 26) % 26;
            }
            j++;
        } else if (isdigit(ciphertext[i])) {
            message += '0' + ((ciphertext[i] - '0') - (key[j % key.length()] - '0') + 10) % 10;
            j++;
        } else {
            message += ciphertext[i];
        }
    }
    return message;
}

int main() {
    string message, key;
    cout << "Enter the message to be encrypted: ";
    getline(cin, message);
    cout << "Enter the substitution key: ";
    getline(cin, key);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    string ciphertext = encrypt(message, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decrypted = decrypt(ciphertext, key);
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}
