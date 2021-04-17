
#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 
  
struct Item  
{ 
    int value, weight; 
}; 
  
// Comparison function to sort Item according to val/weight 
// ratio 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / (double)a.weight; 
    double r2 = (double)b.value / (double)b.weight; 
    return r1 > r2; 
} 
  double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    int CurWeight=0;
    double finalRes=0.0;
    sort(arr, arr+n,cmp);
    for(int i=0;i<n;i++){
        if(CurWeight+arr[i].weight<=W)
            {
                CurWeight+=arr[i].weight;
                finalRes+=arr[i].value;
            }
        else 
            {
                int rem=W-CurWeight;
                finalRes=finalRes+(arr[i].value*(double(rem)/double(arr[i].weight)));
                break;
            }

        
    }
    return finalRes;
}
  int main() 
{ 
    int W = 50; //    Weight of knapsack 
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n)<<endl; 
    return 0; 
}