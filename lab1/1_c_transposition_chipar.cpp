#include<bits/stdc++.h>
using namespace std;

string encrypt(string &message, int row, int key){
    vector<vector<char>> chiper_text(row+1, vector<char>(key));
    string encrypt_msg_str;
    int p=0;
    for(int i=0;i<row+1;i++){
        for(int j=0;j<key;j++){
            chiper_text[i][j]=message[p];
            cout<<chiper_text[i][j]<<" ";
            p++;
        }
        cout<<endl;
    }

    for(int i=0;i<chiper_text[0].size();i++){
        for(int j=0;j<chiper_text.size();j++){
            encrypt_msg_str.push_back(chiper_text[j][i]);
        }
    }
    return encrypt_msg_str;
}

string decrypt(string &encrypt_msg, int row, int key){
    vector<vector<char>> chiper_text(row+1, vector<char>(key));
    string message;
    int p=0;
    for(int i=0;i<key;i++){
        for(int j=0;j<row+1;j++){
            chiper_text[j][i]=encrypt_msg[p];
            cout<<chiper_text[j][i]<<" ";
            p++;
        }
        cout<<endl;
    }

    for(int i=0;i<chiper_text.size();i++){
        for(int j=0;j<chiper_text[0].size();j++){
            message.push_back(chiper_text[i][j]);
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
    int row=message.size()/key;
    
    string encrypt_msg=encrypt(message,row,key);

    // cout<<encrypt_msg.size();
    // cout<<"Encrypted Message: "<<endl;
    
    // for(int i=0;i<encrypt_msg.size();i++){
    //     for(int j=0;j<encrypt_msg[0].size();j++){
    //         cout<<encrypt_msg[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"Encrypted Message: "<<encrypt_msg<<endl;
    string decrypt_msg=decrypt(encrypt_msg, row, key);
    cout<<"Decrypted Message: "<<decrypt_msg<<endl;
}