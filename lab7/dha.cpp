#include <bits/stdc++.h>
using namespace std;

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b, long long int P)
{
	if (b == 1)
		return a;
	else
		return (((long long int)pow(a, b)) % P);
}

int main()
{
	long long int P, G, x, a, y, b, ka, kb;

	// Both the persons will be agreed upon the
	// public keys G and P

    // A prime number P is taken
	P = 23; 
	cout << "The value of P : " << P << endl;

    // A primitive root for P, G is taken
	G = 9; 
	cout << "The value of G : " << G << endl;

	
    // Alice will choose the private key a
    // a is the chosen private key
	a = 4; 
	cout << "The private key a for Alice : " << a << endl;
    
    // gets the generated key
	x = power(G, a, P); 

	// Bob will choose the private key b
	b = 3; // b is the chosen private key
	cout << "The private key b for Bob : " << b << endl;

    // gets the generated key
	y = power(G, b, P); 

	// Generating the secret key after the exchange of keys
	
    // Secret key for Alice
    ka = power(y, a, P); 
    cout << "Secret key for the Alice is : " << ka << endl;
	
    // Secret key for Bob
    kb = power(x, b, P); 
	cout << "Secret key for the Bob is : " << kb << endl;
	
	return 0;
}
