#include<iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace std;

int bubble_sort_swapped(int* arr, int n)  
{  
    int i, j,count=0,swapped=0;  
    for (i = 0; i < n-1; i++){
     for (j = 0; j < n-i-1; j++)  
        {
            // count++;
        if (arr[j] > arr[j+1]) {
             swapped++; 
            swap(arr[j], arr[j+1]); 
            
        }
        }
    }   
            
             return swapped;
}
int  bubble_sort_comparision(int* arr, int n)  
{  
    int i, j,count=0,swapped=0;  
    for (i = 0; i < n-1; i++){
     for (j = 0; j < n-i-1; j++)  
        {count++;
        if (arr[j] > arr[j+1]) {
            //  swapped++; 
            swap(arr[j], arr[j+1]); 
            
        }
        }
    }   
            
               return count;
}

void swap(int *xp, int *yp)  
{  
   
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}



#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;
int main(){
   int N=50;
   cout<<"n  "<<"comarisions  "<<"swapped "<<endl;
  for(int n=1;n<N+1;n++){
       cout<<n<<"         ";
    srand(time(0));
int* arr=new int[n];

for(int i=0;i<n;i++){
arr[i]=rand();
}
cout<<bubble_sort_comparision(arr,  n)<<"      " ;
//worst senario for bubble sort 
for(int i=0;i<n;i++){
arr[i]=rand();
}
cout<<bubble_sort_swapped(arr,  n)<<"       " ;
//best_case senario for insertion sort 


cout<<endl;
}
  }
