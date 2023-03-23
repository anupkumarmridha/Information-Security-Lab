#include <bits/stdc++.h>
using namespace std;

class A51 {
public:
    A51(string key, string frame) {
        // convert key and frame strings to bitsets
        bitset<64> keyBits(key);
        bitset<22> frameBits(frame);

        // initialize registers with key and frame values
        for (int i = 0; i < 19; i++) {
            r1[i] = keyBits[i+8];
        }
        for (int i = 0; i < 22; i++) {
            r2[i] = keyBits[i+29];
        }
        for (int i = 0; i < 23; i++) {
            r3[i] = keyBits[i+51];
        }

        // run clocking algorithm to set registers to frame value
        for (int i = 0; i < 100; i++) {
            clock();
        }
        r1 ^= frameBits.to_ulong();
        r2 ^= frameBits.to_ulong();
        r3 ^= frameBits.to_ulong();
    }

    string generateKeystream(int length) {
        string keystream = "";
        for (int i = 0; i < length; i++) {
            clock();
            int maj = (r1[8] & r2[10]) ^ (r1[8] & r3[10]) ^ (r2[10] & r3[10]);
            int z = (r1[18] ^ r2[21] ^ r3[22]);
            keystream += to_string(z);
        }
        return keystream;
    }

private:
    bitset<19> r1;
    bitset<22> r2;
    bitset<23> r3;

    void clock() {
        int maj = (r1[8] & r2[10]) ^ (r1[8] & r3[10]) ^ (r2[10] & r3[10]);
        if (r1[8] == maj) {
            bitset<19> temp = r1;
            r1 = temp >> 1;
            r1[18] = temp[8] ^ temp[13] ^ temp[16] ^ temp[18];
        }
        if (r2[10] == maj) {
            bitset<22> temp = r2;
            r2 = temp >> 1;
            r2[21] = temp[10] ^ temp[20] ^ temp[21];
        }
        if (r3[10] == maj) {
            bitset<23> temp = r3;
            r3 = temp >> 1;
            r3[22] = temp[7] ^ temp[20] ^ temp[21] ^ temp[22];
        }
    }
};

int main() {
    // initialize A5/1 with key and frame values
    string key = "0100000101101100010010001000010100000001010010000111010101101001";
    string frame = "0000000100000000000000";
    A51 a51(key, frame);

    // generate keystream and print it
    string keystream = a51.generateKeystream(228);
    cout << "Keystream: " << keystream << endl;

    return 0;
}
