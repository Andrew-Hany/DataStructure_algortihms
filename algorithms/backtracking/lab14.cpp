#include <iostream>
#include <vector>
using namespace std;






void print(vector<int>&A, int size,int target_sum)
{
    int summ=0;
	for(int i = 0; i < size; i++)
	{
	    summ+=A[i];

	}
	if(summ==target_sum){
	    	for(int i = 0; i < size; i++)
	{

		cout << A[i] << " ";
	}
	cout << endl;
	}
	
}

void sum_sets(vector<int>&weights, vector<int> &A,int Wsize, int Asize,int sum, int x,int const target_sum)
{
    //base case
	if (target_sum == sum )
	{
		
		print(A, Asize,target_sum);
		sum_sets(weights, A, Wsize, Asize - 1,sum - weights[x], x + 1, target_sum);
		return;
	}
	else
	{
		for(int i = x; i < Wsize; i++)
		{
			A[Asize] = weights[i];
			sum_sets(weights, A, Wsize, Asize + 1,sum + weights[i], i + 1, target_sum);
		}
	}
}

void TopFunction(vector<int>&weights, int size, 
					int target_sum)
{
	vector<int> x(size);
	sum_sets(weights, x, size,0, 0, 0, target_sum);
}

int main()
{
    	cout<<"---------Test case 1-----"<<endl;
	vector<int> weights= {5,7,10,12,15,18,20 };
	TopFunction(weights, weights.size(), 35);
	cout<<"---------Test case 2------"<<endl;
	weights.clear();
		 weights= {1,2,3,4,5};
	TopFunction(weights, weights.size(), 10);
	return 0;
}


