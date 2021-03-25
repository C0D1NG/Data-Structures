#include <bits/stdc++.h> 
using namespace std; 

void SieveOfEratosthenes(int n) 
{ 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or equal to the square of it 
			// numbers which are multiple of p and are less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 

	for (int p=2; p<=n; p++) 
	if (prime[p]) 
		cout << p << " "; 
} 

int main() 
{ 
	int n = 30; 
	cout << n << endl; 
	SieveOfEratosthenes(n); 
	return 0; 
} 
