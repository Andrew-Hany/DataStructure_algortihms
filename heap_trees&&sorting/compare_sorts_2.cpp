#include<iostream>
#include <stdlib.h>    
#include <time.h> 

using namespace std;

int  insertion_sort(int arr[], int n)

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

void heapify(int arr[], int n, int i,int&count) 
{ 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

 
    if(l < n)
        {
            count++;
            // cout<<count<<". "<<arr[largest]<< "\t<\t"<<arr[l]<<endl;
        }
    if (l < n && arr[l] > arr[largest]) 
            largest = l;
           
       
    if (r < n)
    {
            count++;
        // cout<<count<<". "<<arr[largest]<< "\t<\t"<<arr[r]<<endl;
    }
    if (r < n && arr[r] > arr[largest]) 
          largest = r; 
      

    if (largest != i) { 
        
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest,count); 
    } 
}

void build_heap(int arr[], int n,int&count)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i,count);
}
  
int heap_sort(int arr[], int n) 
{
   
    int count=0;
    build_heap(arr, n,count);
  
     
    for (int i = n - 1; i >= 0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0,count); 
    } 
    return count;
} 

int main(){

   int N=50;
    
     cout<<"----------------------------sorted array-------------------------\n";
     cout<<"\t\tn\t"<<"heap_sort\t"<<"insertion_sort\n";
     for(int n=1;n<N+1;n++){
         cout<<"\t\t"<<n<<"\t\t";
         int  arr[n];


            for(int i=0;i<n;i++){

            arr[i]=i;
            }
        cout<< heap_sort(arr, n)<<"\t\t" ;

            for(int i=0;i<n;i++)
            {
            arr[i]=i+1;
            }
        cout<<insertion_sort(arr,  n)<<"\t\t";
    cout<<endl;

}
 cout<<"\n---------------------------- Inversely sorted array-------------------------\n";
cout<<"\t\tn\t"<<"heap_sort\t"<<"insertion_sort\n";
 for(int n=1;n<N+1;n++){
         cout<<"\t\t"<<n<<"\t\t";
         int  arr[n];


            for(int i=0;i<n;i++){

            arr[i]=n-i;
            }
        cout<< heap_sort(arr, n)<<"\t\t" ;

            for(int i=0;i<n;i++)
            {
            arr[i]=n-i;
            }
        cout<<insertion_sort(arr,  n)<<"\t\t";
    cout<<endl;

}
cout<<"\n---------------------------- Randomly initialized array-------------------------\n";
cout<<"\t\tn\t"<<"heap_sort\t"<<"insertion_sort\n";
 for(int n=1;n<N+1;n++){
         cout<<"\t\t"<<n<<"\t\t";
         srand(time(0));
         int  arr[n];
         int array[n];
            for(int i=0;i<n;i++){
            array[i]=rand()%n-1;
            }

            for(int i=0;i<n;i++)
            arr[i]=array[i];
    
        cout<< heap_sort(arr, n)<<"\t\t" ;

             for(int i=0;i<n;i++)
            arr[i]=array[i];
    
        cout<<insertion_sort(arr,  n)<<"\t\t";
    cout<<endl;

}
}