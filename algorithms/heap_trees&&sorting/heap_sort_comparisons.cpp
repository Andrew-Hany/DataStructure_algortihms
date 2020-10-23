
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i,int&count) 
{ 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

 
    if(l < n)
        {
            count++;
            cout<<count<<".\t"<<arr[largest]<< "\t<\t"<<arr[l]<<endl;
        }
    if (l < n && arr[l] > arr[largest]) 
            largest = l;
           
       
    if (r < n)
    {
            count++;
        cout<<count<<".\t"<<arr[largest]<< "\t<\t"<<arr[r]<<endl;
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
    cout<<"Comparisons of build_heap:\n";
    int count=0;
    build_heap(arr, n,count);
    cout<<"Comparisons after build_heap:\n";
     
    for (int i = n - 1; i >= 0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0,count); 
    } 
    return count;
} 
int main(){
    int array[10]={4,1,3,2,16,9,10,14,8,7};
  heap_sort(array, 10);

}