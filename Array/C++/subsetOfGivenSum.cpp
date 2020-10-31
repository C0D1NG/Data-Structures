#include <bits/stdc++.h> 
using namespace std; 

#define maxN 20 
#define maxSum 50 
#define minSum 50 
#define base 50 

int dp[maxN][maxSum + minSum]; 
bool v[maxN][maxSum + minSum]; 

// Function to return the required count 

int findCount(int* arr, int i, int required_sum, int n) 
{ 
	// Base case 
	if (i == n) { 
		if (required_sum == 0) return 1; 
		else return 0; 
	} 

	if (v[i][required_sum + base]) 
		return dp[i][required_sum + base]; 

	v[i][required_sum + base] = 1; 

	// Recurrence relation 
	dp[i][required_sum + base] = findCount(arr, i + 1, required_sum, n) + findCount(arr, i + 1, required_sum - arr[i], n); 
	return dp[i][required_sum + base]; 
} 

int main() 
{ 
	int arr[] = { 1, 2, 3, 3 }; 
	int n = sizeof(arr) / sizeof(int); 
	int x = 6; 
	cout << findCount(arr, 0, x, n); 
	return 0; 
} 
