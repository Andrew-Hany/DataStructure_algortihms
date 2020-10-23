#include <iostream>
#include <algorithm>
using namespace std;

// Partition using Lomuto partition scheme
int Partition(int a[], int start, int end, int &swapped)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[end];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = start;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (int i = start; i < end; i++)
	{
        
         
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
			swapped++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[end]);
	swapped++;

	// return pIndex (index of pivot element)
	return pIndex;
}

// QuickSort routine
void  quicksort_swapped(int *a ,int start, int end, int &swapped)
{
	// base condition
	if (start >= end)
		return ;

	// rearrange the elements across pivot
	int pivot = Partition(a, start, end,swapped);

	// recur on sub-array containing elements that are less than pivot
	quicksort_swapped(a, start, pivot - 1,swapped);

	// recur on sub-array containing elements that are more than pivot
	quicksort_swapped(a, pivot + 1, end,swapped);

    // return swapped;
}

int  quicksort_swapped(int *a ,int n)
{
	int swapped=0;
	quicksort_swapped(a,0,  n-1,swapped);
	return swapped;
}
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

// C++ implementation of quicksort algorithm
int main(){
   int N=10;

cout<<endl;
  cout<<"n"<<"      	quicksort_swapped  " <<" bubble_sort_swapped"<<endl;
      
       for(int n=1;n<N+1;n++){
            cout<<n<<"         ";
           
    srand(time(0));
int* arr=new int[n];
//best_case senario for bubble sort 
for(int i=0;i<n;i++){
arr[i]=rand();
}
cout<<quicksort_swapped(arr,  n)<<"                       " ;
for(int i=0;i<n;i++){
arr[i]=rand();
}
cout<<bubble_sort_swapped(arr,  n)<<"                    " ;
cout<<endl;
  cout<<endl;
}
}
