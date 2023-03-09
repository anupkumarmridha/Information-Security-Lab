#include<bits/stdc++.h>
using namespace std;

string encrypt(string plaintext, int rows, int cols) {
    vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
    int k = 0; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (k < plaintext.size()) {
                matrix[i][j] = plaintext[k++];
            }
        }
    }

    // Read the matrix in a zig-zag pattern and append to the ciphertext
    string ciphertext = "";
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) { // left-to-right
            for (int j = 0; j < cols; j++) {
                ciphertext += matrix[i][j];
            }
        } else { // right-to-left
            for (int j = cols - 1; j >= 0; j--) {
                ciphertext += matrix[i][j];
            }
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int rows, int cols) {
    vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
    int k = 0;

    // Fill the matrix with the ciphertext characters
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (k < ciphertext.size()) {
                matrix[i][j] = ciphertext[k++];
            }
        }
    }

    // Read the matrix in a zig-zag pattern and append to the plaintext
    string plaintext = "";
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                plaintext += matrix[i][j];
            }
        } else { // right-to-left
            for (int j = cols - 1; j >= 0; j--) {
                plaintext += matrix[i][j];
            }
        }
    }

    return plaintext;
}

int main() {
    string plaintext;
    cout<<"Enter the message: "<<endl;
    getline(cin, plaintext);
    int rows = 4;
    int cols = 6;
    string ciphertext = encrypt(plaintext, rows, cols);
    string decryptedtext = decrypt(ciphertext, rows, cols);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decryptedtext: " << decryptedtext << endl;

    return 0;
}
