#include <bits/stdc++.h>
using namespace std;
string decryption(string msg, int key[])
{
    vector<int> register_x(19, 0);
    vector<int> register_y(22, 0);
    vector<int> register_z(23, 0);
    int index = 0;
    for (int i = 0; i < 19; i++)
    {
        register_x[i] = key[index];
        index++;
    }
    for (int i = 0; i < 22; i++)
    {
        register_y[i] = key[index];
        index++;
    }
    for (int i = 0; i < 23; i++)
    {
        register_z[i] = key[index];
        index++;
    }
    int x_select = register_x[8];
    int y_select = register_y[10];
    int z_select = register_z[10];
    if (x_select == 0)
    {
        int xor_op = register_x[18] ^ register_x[17] ^ register_x[16] ^ register_x[13];
        rotate(register_x.begin(), register_x.end(), register_x.end());
        register_x[0] = xor_op;
    }
    if (y_select == 0)
    {
        int xor_op = register_y[20] ^ register_y[21];
        rotate(register_y.begin(), register_y.end(), register_y.end());
        register_y[0] = xor_op;

    }
    if (z_select == 0)
    {
        int xor_op = register_z[20] ^ register_z[21] ^ register_z[22];
        rotate(register_z.begin(), register_z.end(), register_z.end());
        register_z[0] = xor_op;
    }
    for (int i = 0; i < msg.size(); i++)
    {
        msg[i] ^= (register_x[18] ^ register_y[21] ^ register_z[22]);
    }
    return msg;
}
string encryption(string msg, int key[])
{
    vector<int> register_x(19, 0);
    vector<int> register_y(22, 0);
    vector<int> register_z(23, 0);
    int index = 0;
    for (int i = 0; i < 19; i++)
    {
        register_x[i] = key[index];
        index++;
    }
    for (int i = 0; i < 22; i++)
    {
        register_y[i] = key[index];
        index++;
    }
    for (int i = 0; i < 23; i++)
    {
        register_z[i] = key[index];
        index++;
    }
    int x_select = register_x[8];
    int y_select = register_y[10];
    int z_select = register_z[10];
    if (x_select == 0)
    {
        int xor_op = register_x[18] ^ register_x[17] ^ register_x[16] ^ register_x[13];
        rotate(register_x.begin(), register_x.end(), register_x.end());
        register_x[0] = xor_op;
    }
    if (y_select == 0)
    {
        int xor_op = register_y[20] ^ register_y[21];
        rotate(register_y.begin(), register_y.end(), register_y.end());
        register_y[0] = xor_op;
    }
    if (z_select == 0)
    {
        int xor_op = register_z[20] ^ register_z[21] ^ register_z[22];
        rotate(register_z.begin(), register_z.end(), register_z.end());
        register_z[0] = xor_op;
    }
    for (int i = 0; i < msg.size(); i++)
    {
        msg[i] ^= (register_x[18] ^ register_y[21] ^ register_z[22]);
    }
    return msg;
}
int main()
{
string data = "This is a secret message";
int key[] = {1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0};
string encrypt = encryption(data, key);
cout << "Encrypted message is: ";
cout << encrypt << endl;
string decrypt = decryption(encrypt, key);
cout << "Decrypted message is: ";
cout << decrypt << endl;
}