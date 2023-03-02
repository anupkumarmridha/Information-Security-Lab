#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i] ^ key[i];
        ciphertext += c;
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i] ^ key[i];
        plaintext += c;
    }
    return plaintext;
}

int main() {
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    string key;
    /*
    default_random_engine and uniform_int_distribution<int> are C++ standard library classes for generating pseudo-random numbers.
    default_random_engine is a class that provides a source of randomness. When you create an instance of this class, you can use it to generate a sequence of pseudo-random numbers
    uniform_int_distribution<int> is a class that takes a range and produces a distribution of numbers uniformly distributed across that range. In this case, the range is from 0 to 255.

    */
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 255);
    for (int i = 0; i < plaintext.length(); i++) {
        char c = distribution(generator);
        key += c;
    }
    string ciphertext = encrypt(plaintext, key);
    cout << "The ciphertext is: " << ciphertext << endl;
    string decrypted_text = decrypt(ciphertext, key);
    cout << "The decrypted text is: " << decrypted_text << endl;
    return 0;
}
