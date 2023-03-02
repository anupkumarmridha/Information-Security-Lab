#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string encrypt(string message, vector<string> key) {
    string ciphertext = "";
    for (int i = 0; i < message.length(); i += 2) {
        string block = message.substr(i, 2);
        int row, col;
        for (int r = 0; r < key.size(); r++) {
            col = key[r].find(block[0]);
            if (col != string::npos) {
                row = r;
                break;
            }
        }
        ciphertext += key[(row + 1) % key.size()][col];
        for (int r = 0; r < key.size(); r++) {
            col = key[r].find(block[1]);
            if (col != string::npos) {
                row = r;
                break;
            }
        }
        ciphertext += key[(row + 1) % key.size()][col];
    }
    return ciphertext;
}

string decrypt(string ciphertext, vector<string> key) {
    string message = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        string block = ciphertext.substr(i, 2);
        int row, col;
        for (int r = 0; r < key.size(); r++) {
            col = key[r].find(block[0]);
            if (col != string::npos) {
                row = r;
                break;
            }
        }
        message += key[(row - 1 + key.size()) % key.size()][col];
        for (int r = 0; r < key.size(); r++) {
            col = key[r].find(block[1]);
            if (col != string::npos) {
                row = r;
                break;
            }
        }
        message += key[(row - 1 + key.size()) % key.size()][col];
    }
    return message;
}

int main() {
    string message;
    vector<string> key;
    int rows;
    cout << "Enter the message to be encrypted: ";
    getline(cin, message);
    cout << "Enter the number of rows for the polygraphic key: ";
    cin >> rows;
    cin.ignore();
    cout << "Enter the polygraphic key one row at a time: " << endl;
    for (int i = 0; i < rows; i++) {
        string row;
        getline(cin, row);
        transform(row.begin(), row.end(), row.begin(), ::toupper);
        key.push_back(row);
    }
    string ciphertext = encrypt(message, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decrypted = decrypt(ciphertext, key);
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}
