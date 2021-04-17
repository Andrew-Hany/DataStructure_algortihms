#include<bits/stdc++.h> 
using namespace std; 
  
// Returns min number of squares needed 
int minimumSquare(int a, int b) 
{ 
    long long result = 0, rem = 0; 
  
    //sorting to use the a as the bigger one always
    if (a < b) 
        swap(a, b); 
  
    // Iterate until small size side is 
    // greater then 0 
    while (b > 0) 
    { 
        // updating result with the value of the square available in this rectangle
        result += a/b; 
        //computing the remainder which is the length which can not make squares
        long long rem = a % b; 

        // give b to a , as b is the smaller now 
        // and then give the reaminder to b
        a = b; 
        b = rem; 
    } 
  //print the result
    return result; 
} 
  
// Driver code 
int main() 
{ 
    int n = 13, m = 29; 
    cout << minimumSquare(n, m); 
    return 0; 
} 