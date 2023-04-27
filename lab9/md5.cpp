#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <openssl/md5.h>

using namespace std;

string md5(string input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((const unsigned char *)input.c_str(), input.length(), digest);

    stringstream ss;
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)digest[i];
    }

    return ss.str();
}

int main() {
    string input = "Hello, world!";
    string output = md5(input);
    cout <<"Hash Value: " <<output << endl;

    return 0;
}
