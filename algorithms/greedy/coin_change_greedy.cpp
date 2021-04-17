#include<iostream>
#include<vector>
using namespace std;


void findMin(int V,int coins[], int n){
    sort(coins, coins + n); 
    int i=0;
    vector<int>res;
for(int i =n-1;i>=0;i--)
    while(V-coins[i]>=0){
       V= V-coins[i];
       res.push_back(coins[i]);

    }
for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}
cout<<endl;

}


int main(){
    int coins[] = { 1, 2, 5, 10, 20, 
               50, 100, 500, 1000 }; 
int n = sizeof(coins) / sizeof(coins[0]); 

  int V = 93; 
  cout<<"coins: ";
    findMin(V, coins,n); 
    return 0; 
}