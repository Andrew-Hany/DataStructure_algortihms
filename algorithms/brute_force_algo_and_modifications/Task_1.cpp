#include<iostream>
using namespace std;

int s_vers_1(int n){

    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else    
         return (s_vers_1(n-1)+s_vers_1(n-2));
}
int main(){
for(int i=0;i<15;i++)
cout<<i<<"\t\t"<<s_vers_1(i)<<endl;
    return 0;
}