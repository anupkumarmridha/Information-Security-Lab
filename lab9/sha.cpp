#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

string sha256(string input) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)input.c_str(), input.length(), digest);

    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)digest[i];
    }

    return ss.str();
}

int main() {
    string input = "Hello, world!";
    string output = sha256(input);
    cout <<"Hash value using SHA256: "<<output << endl;

    return 0;
}
