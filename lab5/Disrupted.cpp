#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, string key)
{
    unordered_map<int, int> mp;
    string secret_key = key;
    sort(secret_key.begin(), secret_key.end());
    int n = key.size();
    for (int i = 0; i < n; i++)
    {
        mp[i] = key.find(secret_key[i]);
    }

    vector<vector<char>> v(n, vector<char>(n, '*'));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= mp[i]; j++)
        {
            if (k < text.size())
                v[i][j] = text[k++];
            else
                break;
        }
    }

    if (k < text.size())
    {
        for (int i = 0; i < n; i++)
            for (int j = mp[i] + 1; j < n; j++)
            {
                if (k < text.size())
                    v[i][j] = text[k++];
                else
                    break;
            }
    }

    string chiper_text = "";

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][mp[j]] != '*')
                chiper_text += v[i][mp[j]];
        }
    }

    return chiper_text;
}


string decrypt(string chiper_text, string key)
{
    unordered_map<int, int> mp;
    string secret_key = key;
    sort(secret_key.begin(), secret_key.end());
    int n = key.size();
    for (int i = 0; i < n; i++)
    {
        mp[i] = key.find(secret_key[i]);
    }

    vector<vector<char>> v(n, vector<char>(n, '*'));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= mp[i]; j++)
        {
            if (k < chiper_text.size())
            {
                v[i][j] = '#';
                k++;
            }
            else
                break;
        }
    }

    if (k < chiper_text.size())
    {
        for (int i = 0; i < n; i++)
            for (int j = mp[i] + 1; j < n; j++)
            {
                if (k < chiper_text.size())
                {
                    v[i][j] = '#';
                    k++;
                }
                else
                    break;
            }
    }

    k = 0;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][mp[j]] == '#')
                v[i][mp[j]] = chiper_text[k++];
        }
    }

    string plain_text = chiper_text;
    k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= mp[i]; j++)
        {
            if (k < chiper_text.size())
            {
                plain_text[k++] = v[i][j];
            }
            else
                break;
        }
    }

    if (k < chiper_text.size())
    {
        for (int i = 0; i < n; i++)
            for (int j = mp[i] + 1; j < n; j++)
            {
                if (k < chiper_text.size())
                {
                    plain_text[k++] = v[i][j];
                }
                else
                    break;
            }
    }

    return plain_text;
}


int main()
{
    string message = "This is a sample test message", key = "BIRTHDAY";
    string cipher_text = encrypt(message, key);
    string decrypted_text = decrypt(cipher_text,key);
    cout << "Encrypted message : " << cipher_text<< endl;
    cout << "Decrypted message : " << decrypted_text << endl;

    return 0;
}
