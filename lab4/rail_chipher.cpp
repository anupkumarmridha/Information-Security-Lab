
#include <bits/stdc++.h>
using namespace std;


string encrypt(string text, int depth)
{
	char rail[depth][(text.length())];

	for (int i=0; i < depth; i++){
		for (int j = 0; j < text.length(); j++){
			rail[i][j] = '\n';
        }
    }

	bool down = false;
	int row = 0, col = 0;
	
    for (int i=0; i < text.length(); i++)
	{
		if (row == 0 || row == depth-1){
			down = !down;
        }

		rail[row][col++] = text[i];
        
        if(down){
            row++;
        }
        else{
            row--;
        }
	}

	string result;
	for (int i=0; i < depth; i++){
		for (int j=0; j < text.length(); j++){
			if (rail[i][j]!='\n'){
				result.push_back(rail[i][j]);
            }
        }
    }
	return result;
}

string decrypt(string cipher, int depth)
{
	char rail[depth][cipher.length()];
	for (int i=0; i < depth; i++){
		for (int j=0; j < cipher.length(); j++){
			rail[i][j] = '\n';
        }
    }

	bool down;
	int row = 0, col = 0;
	
    for (int i=0; i < cipher.length(); i++)
	{
		if (row == 0){
			down = true;
        }
		if (row == depth-1){
			down = false;
        }
		
        rail[row][col++] = '*';
		if(down){
            row++;
        }
        else{
            row--;
        }
	}


	int index = 0;
	for (int i=0; i<depth; i++){
		for (int j=0; j<cipher.length(); j++){
			if (rail[i][j] == '*' && index<cipher.length()){
				rail[i][j] = cipher[index++];
            }
        }
    }
	string result;
	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		if (row == 0){
			down = true;
        }
		
        if (row == depth-1){
            down = false;
        }

		if (rail[row][col] != '*'){
            result.push_back(rail[row][col++]);
        }
		
        if(down){
            row++;
        }
        else{
            row--;
        }
	}
	return result;
}
int main()
{
    string msg;
    cout<<"Enter The message: "<<endl;
    getline(cin, msg);
    cout<<"Enter Depth: "<<endl;
    int depth;
    cin>>depth;
    string chipher_text=encrypt(msg, depth);
    cout<<"Chipher Text: "<<chipher_text<<endl;
    string decrypted_msg=decrypt(chipher_text, depth);
    cout<<"Normal Text: "<<decrypted_msg<<endl;
	return 0;
}
