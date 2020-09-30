#include<iostream>
#include<vector>
using namespace std;

int s_vers_2(int n)
    {
        vector<int>x;
x.resize(n+1);
    
   for(int i=0;i<=n;i++){
    if(i==0)
       x[i]=0;  
    else if(i==1)
       x[i]=1;
    else   
        x[i]=x[i-1]+x[i-2];

        }
   return x[n];
}
int main(){
for(int i=0;i<15;i++)
cout<<i<<"\t\t"<<s_vers_2(i)<<endl;
    return 0;
}