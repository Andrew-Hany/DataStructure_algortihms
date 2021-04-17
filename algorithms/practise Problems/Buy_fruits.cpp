/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int Partition(vector<int>&a , int start, int end)
{

	int pivot = a[end];

	int pIndex = start;

	for (int i = start; i < end; i++)
	{
     
         
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	swap (a[pIndex], a[end]);
	return pIndex;
}


void  quicksort_comparisions(vector<int>&a  ,int start, int end)
{

	if (start >= end)
		return ;
	int pivot = Partition(a, start, end);
	quicksort_comparisions(a, start, pivot - 1);
	quicksort_comparisions(a, pivot + 1, end);

  
}
void quicksort(vector<int>&a ,int n)
{

	quicksort_comparisions(a,0,  n-1);

}

   ///-------------------------------//
bool fruit(vector<int>weight,int value){
  //we need to add some other possible weight to the array 
    for(int i=weight.size()-1;i>=0;i--){
        if(value>=weight[i])
        {
            value =value-weight[i];
            // cout<<weight[i]<<endl;
        }
         cout<<weight[i]<<endl;
        if(value==0)
        return true;
       
       

    
    }
    return false;
}


int main()
{
int array[200]={0};
    int value=26;
    vector<int>weight={11,9,1,5};
    int size=weight.size();
    int sum=0;
   for(int i=0;i<size;i++)
   sum=sum+weight[i];
    
for(int i=0;i<size;i++)//1,2,5,10
    for(int j=i+1;j<size;j++)//2,5,10
        {
            if(array[weight[i]-weight[j]]==0){
            weight.push_back(abs(weight[i]-weight[j]));
            array[weight[i]-weight[j]]++;
                
            }
            // cout<<abs(weight[i]-weight[j]);
        }

   quicksort(weight ,weight.size());
    if(fruit(weight,value)&&value<= sum)
       cout <<"yes, we can weigh this amount for you"<<endl;
    else 
       cout <<"sorry,we cant weight this amount for you"<<endl;
   
    return 0;
}
