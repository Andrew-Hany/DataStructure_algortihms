#include<iostream>
#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;


int insertion_sort_comparision(int* arr, int n)  
{  
    int i, key, j,count=0,counti=0;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        count++;
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
 
        while (j >= 0 && arr[j] > key) 
        {  
          
            counti++;
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        //we counting the first comparision (the fist iteration in while using cout)
        //so counti =the number of comparisons + number of iteration if it is best case
        //so i deleted it
        if(counti>0)
        counti--;
        arr[j + 1] = key;  
    }  
    count=count+counti;
   
return count;
} 



using namespace std;
int main(){
   int N=10;
   cout<<"n  "<<"insertion-best  "<<"insertion-worst"<<endl;
  for(int n=1;n<N+1;n++){
       cout<<n<<"         ";
    srand(time(0));
int* arr=new int[n];

//best_case senario for insertion sort 
for(int i=0;i<n;i++){
arr[i]=i;
}
cout<<insertion_sort_comparision(arr,  n)<<"              " ;

//worst senario for insertion sort 
for(int i=0;i<n;i++){
arr[i]=n-1-i;
}
cout<<insertion_sort_comparision(arr,  n)<<"                " ;
cout<<endl;
}
  }
