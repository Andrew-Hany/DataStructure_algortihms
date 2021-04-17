#include <bits/stdc++.h>
using namespace std;
 
//to find the max
int max(int a, int b) { return (a > b) ? a : b; }
 

int lcs(char* X, char* Y, int m, int n);
 
//the function that will compute shortest SuperSequence and it will call LCS which will use its value 
int shortestSuperSequence(char* X, char* Y)
{
    int m = strlen(X), n = strlen(Y);
 
    // find lcs
    int l = lcs(X, Y, m, n);
 
    //here we need to add the length of both strings and then subtract the 
    // lengths - length of lcs
    return (m + n - l);
}

// now we need to compute LCS by dymaic programming 
int lcs(char* X, char* Y, int m, int n)
{
    // intializing the array of the DP
    int L[m + 1][n + 1];
    // the pointer
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            //base case
            if (i == 0 || j == 0)
                L[i][j] = 0;
            //if the the characters are equal, then get the diagnoal and add to a zero
            // we use the diagonal value (as this value is for the previos chars so we need to use it and add to it a 1)
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
 //if they are not equal, we need to check the max cell before 
 // the diagonal will be the same as the above cell or smaller, so we don't need to check it here
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS
    // for X[0..n - 1] and Y[0..m - 1]
    return L[m][n];
}
 
// Driver code
int main()
{\
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
 
    cout << "Length of the shortest supersequence is "
         << shortestSuperSequence(X, Y) << endl;
 
    return 0;
}