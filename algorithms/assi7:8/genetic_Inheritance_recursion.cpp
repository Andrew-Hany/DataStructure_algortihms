/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
 
double genetic_Inheritance(int n, double x){
    //base case

    if(n==0)
    {
    return x;
    }
    else if(n==1)
  {

      return 0.7*genetic_Inheritance( n-1,  x);
      
  }
      

   double sum = 0;
    for (int i=0; i<n; i++)
       sum += genetic_Inheritance( i,  x);
    double aver=(sum)/n;
    return 0.7*(aver);
    
    
    
}


int main()
{
    int average=0;
    int count=0;
    cout<<genetic_Inheritance(3,  1)<<endl;

    return 0;
}
