#include<bits/stdc++.h>
using namespace std;

vector<int> ksa(string key) {
    vector<int> s(256);
    int j = 0;
    for (int i = 0; i < 256; i++) {
        s[i] = i;
    }
    for (int i = 0; i < 256; i++) {
        j = (j + s[i] + key[i % key.size()]) % 256;
        swap(s[i], s[j]);
    }
    return s;
}

string prga(vector<int> s, string data) {
    string keystream = "";
    int i = 0;
    int j = 0;
    for (int k = 0; k < data.size(); k++) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        swap(s[i], s[j]);
        int t = (s[i] + s[j]) % 256;
        int u = s[t];
        keystream += u;
    }
    return keystream;
}

string rc4(string key, string data) {
    vector<int> s = ksa(key);
    string keystream = prga(s, data);
    string result = "";
    for (int i = 0; i < data.size(); i++) {
        int c = data[i] ^ keystream[i];
        result += c;
    }
    return result;
}

int main() {
    
    string key = "mysecretpassword";
    string data = "This is a secret message";
    string ciphertext = rc4(key, data);
    cout << "Encrypted data: ";
    for (int i = 0; i < ciphertext.size(); i++)
        printf("%02X ", (unsigned char) ciphertext[i]);
    cout << endl;
    string plaintext = rc4(key, ciphertext);
    cout << "Decrypted data: " << plaintext << endl;

    return 0;
}
