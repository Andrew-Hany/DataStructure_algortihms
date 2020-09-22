
#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include"bubble_sort.cpp"
#include"insertion.cpp"
using namespace std;
int main(){
   int n=10;
    srand(time(0));
int* arr=new int[n];
for(int i=0;i<n;i++){
    
arr[i]=rand() % 10 + 1;
cout<<arr[i]<<" ";
}
cout<<endl;
insertion_sort(arr,  n) ;
for(int i=0;i<n;i++){

cout<<arr[i]<<" ";
}
}