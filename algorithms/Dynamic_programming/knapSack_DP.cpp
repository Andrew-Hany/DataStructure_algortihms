#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <vector>
using namespace std;

int max(int a, int b) 
{  
    return (a > b) ? a : b;  
} 

int KnapSack_Dp(vector<int>val, vector<int>weight, int C){
   

   int dp[val.size() + 1][C + 1]; 

   for(int i=0;i<=val.size();i++){
       for(int c=0;c<=C;c++){
           if(i==0||c==0)
             dp[i][c]=0;
           else if(c>=weight[i-1]){
            dp[i][c]=max(dp[i-1][c],dp[i-1][c-weight[i-1]]+val[i-1]);
           }
            else 
           dp[i][c]=dp[i-1][c];
        
           }
   
       }
       
   
   
   
    return dp[val.size()][C];
}


int main()
{
  
vector<int>val = { 60, 100, 120 }; 
 vector<int>weight = { 10, 20, 30 }; 
    int C = 50;
   cout<< KnapSack_Dp(val, weight,  C )<<endl;
    return 0;
}