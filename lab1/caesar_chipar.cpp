#include <bits/stdc++.h>
using namespace std;
string encrypt(vector<pair<char,char>> &pr){
    string cipher_text="";	
    for(auto i:pr){
            cipher_text+=i.second;
            cout<<i.first<<" "<<i.second<<endl;
        }
    return cipher_text;
}
string decrypt(vector<pair<char,char>> &pr){
    
    string msg="";
    for(auto i: pr){
        msg+=i.first;
    }
    return msg;
}


int main() {
    string msg;
    cout<<"Enter the message:\n";
    getline(cin,msg);
    vector<pair<char,char>> pr;
    char ch;
    for(int i=0;i<msg.length();i++){
        cout<<"Enter letter for encoding : "<<msg[i]<<endl;
        cin>>ch;
        pr.push_back({msg[i],ch});
    }

    string encrypt_msg=encrypt(pr);
    cout<<"Encrypted message: "<<encrypt_msg<<endl;
    string decrypt_msg = decrypt(pr);
    cout << "Decrypted message: " <<decrypt_msg<<endl;
}