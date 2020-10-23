#include <cmath>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > multiply(   vector<vector<int> >  A, vector<vector<int> >  B)
 {
  
  
      vector<vector<int> > res;
      res.resize(2);
      res[0].resize(2);
          res[1].resize(2);
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
         for (int k=0; k<2; k++)
            res[i][j]+=(A[i][k]*B[k][j]);
          

      return res;
} 
vector<vector<int> > s_vers_3(int n)
    {
     vector<vector<int> >  ideal;
     ideal.resize(2);
     ideal[0].push_back(1);
      ideal[0].push_back(0);
      ideal[1].push_back(0);
      ideal[1].push_back(1);
 vector<vector<int> >  M;
    M.resize(2);
    M[0].push_back(1);
      M[0].push_back(1);
      M[1].push_back(1);
      M[1].push_back(0);
      if(n==0)
      return  ideal;
    else if(n%2==0)
    return  multiply(s_vers_3(n/2),s_vers_3(n/2));
    else 
    return  multiply(M,multiply(s_vers_3((n-1)/2),s_vers_3((n-1)/2)));  
}
int s_vers3(int n){
 return s_vers_3(n)[1][0];
  
}
int main(){
for(int i=0;i<15;i++)
cout<<i<<"\t\t"<<s_vers3(i)<<endl;
    return 0;
}
