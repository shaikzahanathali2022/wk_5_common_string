
#include<bits/stdc++.h> 
using namespace std; 

void printLCSubStr(char* X, char* Y, int m, int n) 
{ 

int LCSuff[m+1][n+1]; 

int len = 0; 
int row, col; 


for (int i=0; i<=m; i++) 
{ 
	for (int j=0; j<=n; j++) 
	{ 
	if (i == 0 || j == 0) 
		LCSuff[i][j] = 0; 

	else if (X[i-1] == Y[j-1]) 
	{ 
		LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
		if (len < LCSuff[i][j]) 
		{ 
			len = LCSuff[i][j]; 
			row = i; 
			col = j; 
		} 
	} 
	else
		LCSuff[i][j] = 0; 
	} 
} 


if (len == 0) 
{ 
	cout << "There is no matching subsequence"; 
	return; 
} 


char* resultStr = new char[len+1]; 
resultStr[len] = '\0'; 


while (LCSuff[row][col] != 0) 
{ 
	resultStr[--len] = X[row-1]; 

	row--; 
	col--; 
} 


cout << "LCS of " << X << " and " << Y << " is "
		<< resultStr; 
} 


int main() 
{ 
	char X[] = "ABAB"; 
	char Y[] = "BABA"; 

	int m = strlen(X); 
	int n = strlen(Y); 

	printLCSubStr(X, Y, m, n); 
	return 0; 
}
