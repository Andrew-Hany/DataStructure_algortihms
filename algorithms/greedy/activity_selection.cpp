#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void printMaxActivities(int s[], int f[],int n){
   
vector<int>index;
index.push_back(0);

int count=0;
      for(int i=1;i<n;i++)
      if(s[i]>=f[count])
      {
          index.push_back(i);
          count=i;
          }

       for(int i=0;i<index.size();i++)
       cout<<index[i]<<" ";

}
int main() 
{ 

    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    //we need to sort them according to their finish time before calling the function
    
    int n = sizeof(s)/sizeof(s[0]); 
    printMaxActivities(s, f, n); 
    return 0; 
} 