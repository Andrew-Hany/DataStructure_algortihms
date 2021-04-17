/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
struct job{
    int start;
    int finish;
    string name;
};
int Partition(vector<job>&a, int start, int end)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[end].finish;

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = start;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (int i = start; i < end; i++)
	{
      
         
		if (a[i].finish <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[end]);

	// return pIndex (index of pivot element)
	return pIndex;
}

// QuickSort routine
void  quicksort_comparisions(vector<job>&a ,int start, int end)
{
	// base condition
	if (start >= end)
		return ;

	// rearrange the elements across pivot
	int pivot = Partition(a, start, end);

	// recur on sub-array containing elements that are less than pivot
	quicksort_comparisions(a, start, pivot - 1);

	// recur on sub-array containing elements that are more than pivot
	quicksort_comparisions(a, pivot + 1, end);

  
}

void  quicksort_comparisions(vector<job>&a ,int n)
{

	quicksort_comparisions(a,0,  n-1);

}


vector<job> maximize_productivity (vector<job>jobs){
    vector<job>list;
    int i; 
     i = 0; 
     int counter=1;
     list.push_back(jobs[i]);
     
     for (int j = 1; j < jobs.size(); j++) 
    { 
   counter++;
      if (jobs[j].start >=jobs[i].finish) 
      { 
        list.push_back(jobs[j]);
          i = j; 
          
      } 
   
    } 
    return list;
}
int main()
{
    vector<job>jobs;
        job x,y,z,a,b,c;
        x.start =1;
        x.finish =2;
        x.name = "job1";
        jobs.push_back(x);
         y.start =3;
        y.finish =4;
        y.name = "job2";
         jobs.push_back(y);
         z.start =0;
        z.finish =6;
        z.name = "job3";
         jobs.push_back(z);
        a.start =5;
        a.finish =7;
        a.name = "job4";
         jobs.push_back(a);
         b.start =8;
        b.finish =9;
        b.name = "job5";
         jobs.push_back(b);
         c.start =5;
        c.finish =9;
        c.name = "job6";
         jobs.push_back(c);
          cout<<  "-----------------------------FIRST TEST CASE----------------------"<<endl;
         for(int i=0;i<maximize_productivity (jobs).size();i++)
            cout<< maximize_productivity (jobs)[i].name<<endl;
       
            jobs.clear();
        x.start =22;
        x.finish =30;
        x.name = "job1";
        jobs.push_back(x);
         y.start =10;
        y.finish =20;
        y.name = "job2";
         jobs.push_back(y);
         z.start =12;
        z.finish =25;
        z.name = "job3";
         jobs.push_back(z);
      
         cout<<  "-----------------------------SECOND  TEST CASE----------------------"<<endl;
       
quicksort_comparisions(jobs ,jobs.size());

         for(int i=0;i<maximize_productivity (jobs).size();i++)
            cout<< maximize_productivity (jobs)[i].name<<endl;//cout the names
 

    return 0;
}
