#include<bits/stdc++.h>
using namespace std;

string encrypt(string msg, int key){
	string cipher_text="";	
	for(int i=0;i< msg.size(); i++){
		if(isupper(msg[i])){
			cipher_text+= char(int(msg[i]+ key- 65)%26+65);
		}
        else if(islower(msg[i])){
			cipher_text+=  char(int(msg[i]+ key- 97)%26+ 97);
		}
        else{
            cipher_text+=" ";
        }
	}
	return cipher_text;
}

string decrypt(string cipher_text, int key){
	string msg="";	
	for(int i=0;i< cipher_text.size(); i++){
		if(isupper(cipher_text[i])){
			msg+= char((int(cipher_text[i]- key- 65)%26+26)%26 + 65);
		}
        else if(islower(cipher_text[i])){
			msg+=  char((int(cipher_text[i]- key- 97)%26+ 26)%26 + 97);
		}
        else{
            msg+=" ";
        }
	}
	return msg;
}
int main(){
	string msg;
	cout<<"Enter Your Message: ";
	getline(cin, msg);
	int key;
	cout<<"Enter key: ";
	cin>>key;
	string cipher_text= encrypt(msg, key);
	
	cout<<"\nEncryption: \n";
	cout<<"Cipher: "<<cipher_text<<endl;
	
	cout<<"\nDecryption:\n";
	cout<<"Plain Text: "<<decrypt(cipher_text, key)<<endl;
}