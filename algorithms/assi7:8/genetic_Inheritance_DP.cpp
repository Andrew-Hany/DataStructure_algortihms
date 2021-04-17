/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
double genetic_Inheritance(int n, double x){
    vector<double>inheritance(n);
    double average=0;
    int i=0;
    int count=0;
  while(n+1!=i){
    if(i==0)
       { inheritance[i]=x;
        average=average+x;
        count++;
        }
    else if(i==1)
       { inheritance[i]=0.7*x;
       average=average+inheritance[i];
       count++;
       }
    else 
        {
            inheritance[i]=0.7*(average/count);
             average=average+inheritance[i];
             count++;
        }
        
    
        i++;
  }
    
    return(inheritance[n]);
}


int main()
{
    cout<<genetic_Inheritance(3,1);

    return 0;
}
