#include<iostream>
#include<vector>
using namespace std;
//same idea as knapSack 
int max(int a, int b) 
{  
    return (a > b) ? a : b;  
} 

int RodCutting(vector<int>lengths,vector<int>prices, int L){
    int dp[lengths.size()+1][L+1];

    for(int i=0;i<=lengths.size();i++){
        for(int l=0;l<=L;l++)
        {
            if(i==0||l==0)
            dp[i][l]=0;
            else if (l>=lengths[i-1])
            dp[i][l]=max(dp[i-1][l],prices[i-1]+dp[i-1][l-lengths[i-1]]);
            else  dp[i][l]= dp[i-1][l];
        }
    }
return dp[lengths.size()][L];
}


int main()
{
vector<int>lengths={1,2,3,4};
vector<int>prices={2,5,7,8};
int L=5;
cout<<RodCutting(lengths,prices,L)<<endl;
}