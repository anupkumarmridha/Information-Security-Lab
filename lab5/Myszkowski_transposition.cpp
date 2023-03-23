#include <bits/stdc++.h>
using namespace std;

string encrypt(string message,string key){
    int col = key.length();
    int row;
    if(message.length() % col == 0) row = message.length()/col;
    else row = message.length()/col + 1;
    char arr[row][col];
    int index=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(index<message.length()){
                if(message[i]==' ')  arr[i][j]=' ';
                else  arr[i][j]=message[index];
                index++;
            }
            else arr[i][j]='#';
        }
    }
    map<int,vector<int>>mp;
    for(int i=0;i<col;i++){
        mp[key[i]-'a'].push_back(i);
    }
    string chipher_text="";
    for(auto x:mp){
       vector<int>v=mp[x.first];
       for(int i=0;i<row;i++){
           for(int j=0;j<v.size();j++){
               chipher_text+=arr[i][v[j]];
           }
       }
    }
    return chipher_text;
}



string decrypt(string chipher_text,string key){
    int col = key.length();
    int row = chipher_text.length()/col;
    char arr[row][col];
    
    map<int,vector<int>>mp;
    for(int i=0;i<col;i++){
        mp[key[i]-'a'].push_back(i);
    }
    int index=0;
    for(auto x:mp){
        vector<int>v=mp[x.first];
        for(int i=0;i<row;i++){
            for(int j=0;j<v.size();j++){
                arr[i][v[j]]=chipher_text[index++];
            }
        }
    }
    string plain_text="";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]=='#') break;
            if(arr[i][j]==' ') plain_text+=' ';
            else plain_text+=arr[i][j];
        }
    }
    return plain_text;
}




int main() {
    string message = "cracking code is super fun";
    string key = "cracking";
    
    string chipher_text = encrypt(message,key);
    cout<<"Encrypted message : "<<chipher_text<<endl;
    string decrypted_text = decrypt(chipher_text,key);
    cout<<"Decrypted message : "<<decrypted_text<<endl;
    return 0;
}