
#include <iostream>
#include <vector>
#include <math.h>
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

   


//////----------------------------------------------------//
int hallowen(vector<int> students, vector<int>  houses){
   vector< bool> HouseReserved;
   HouseReserved.resize(houses.size());
    
    int Time=0;
     int Time1=0;

    for(int i=students.size()-1;i>=0;i--)
      {
          int smalestDis=1232313120,index=0;
          for(int j=0;j<houses.size();j++)
        {
            if(HouseReserved[j]!=1 &&abs(students[i]-houses[j])<smalestDis){
                smalestDis=abs(students[i]-houses[j]);
                
                index=j;
            }
        }
        
        HouseReserved[index]=true;
        if(Time<smalestDis)
        Time=smalestDis;
          
      }
      
                        //----------------//
      HouseReserved.clear();
      HouseReserved.resize(houses.size());
      HouseReserved={0};
      
      for(int i=0;i<students.size();i++)
      {
          int smalestDis=1232313120,index=0;
          for(int j=0;j<houses.size();j++)
        {
            // cout<<HouseReserved[j];
            if(HouseReserved[j]!=1 &&abs(students[i]-houses[j])<smalestDis){
                smalestDis=abs(students[i]-houses[j]);
                index=j;
            }
        }
        HouseReserved[index]=true;
        if(Time1<smalestDis)
        Time1=smalestDis;
          
      }
      if(Time<Time1)
        return Time;
       else
        return Time1;
}
///-------------------------------------------------------------------------//
int main()
{
    vector<int> students={5,6,8,9};//this needs modern c++, so if it does not work on Ur PC put it on online compiler( as i did not do push for vector)
        vector<int> houses={1,2,4,10,12,13,14};
        quicksort(students, students.size());
        quicksort(houses,houses.size());
cout<<hallowen(students,  houses);
    return 0;
}
