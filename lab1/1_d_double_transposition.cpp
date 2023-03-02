#include<bits/stdc++.h>
using namespace std;

string encrypt(string &message, int row, int key){
    vector<vector<char>> chiper_text(row, vector<char>(key));
    string encrypt_msg_str;
    int p=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<key;j++){
            chiper_text[i][j]=message[p];
            cout<<chiper_text[i][j]<<" ";
            p++;
        }
        cout<<endl;
    }

    // First transposition

    for(int i=0;i<chiper_text[0].size();i++){
        for(int j=0;j<chiper_text.size();j++){
            encrypt_msg_str.push_back(chiper_text[j][i]);
        }
    }

    // Second transposition
    vector<vector<char>> chiper_text2(row, vector<char>(key));
    p=0;
    for(int i=0;i<key;i++){
        for(int j=0;j<row;j++){
            chiper_text2[j][i]=encrypt_msg_str[p];
            cout<<chiper_text2[j][i]<<" ";
            p++;
        }
        cout<<endl;
    }

    encrypt_msg_str = "";
    for(int i=0;i<chiper_text2[0].size();i++){
        for(int j=0;j<chiper_text2.size();j++){
            encrypt_msg_str.push_back(chiper_text2[j][i]);
        }
    }

    return encrypt_msg_str;
}

string decrypt(string &encrypt_msg, int row, int key){
    vector<vector<char>> chiper_text(row, vector<char>(key));
    string message;
    int p=0;
    for(int i=0;i<key;i++){
        for(int j=0;j<row;j++){
            chiper_text[j][i]=encrypt_msg[p];
            cout<<chiper_text[j][i]<<" ";
            p++;
        }
        cout<<endl;
    }

    // Second transposition
    vector<vector<char>> chiper_text2(row, vector<char>(key));
    p=0;
    for(int i=0;i<chiper_text[0].size();i++){
        for(int j=0;j<chiper_text.size();j++){
            chiper_text2[j][i]=chiper_text[j][i];
        }
    }

    // Decryption
    for(int i=0;i<chiper_text2.size();i++){
        for(int j=0;j<chiper_text2[0].size();j++){
            message.push_back(chiper_text2[i][j]);
        }
    }
    return message;
}

int main(){
    int key;
    string message;
    cout<<"Enter Your Message: "<<endl;
    getline(cin, message);
    cout<<"Enter the key: "<<endl;
    cin>>key;
    int row = ceil(message.size()/(double)key);

    
    string encrypt_msg=encrypt(message,row,key);

    cout<<"Encrypted Message: "<<encrypt_msg<<endl;
    string decrypt_msg = decrypt(encrypt_msg, row, key);


    cout<<"Decrypted Message: "<<decrypt_msg<<endl;
}