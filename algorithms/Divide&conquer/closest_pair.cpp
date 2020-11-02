

#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;
//////struct to have points
struct  Point
{
  
    int x, y;
};
///////////////////Qick_sort//////////////////////////////
int Partition(Point a[], int start, int end)
{
    // Pick rightmost element as pivot from the array
    int pivot = a[end].x;

    // elements less than pivot will be pushed to the left of pIndex
    // elements more than pivot will be pushed to the right of pIndex
    // equal elements can go either way
    int pIndex = start;

    // each time we finds an element less than or equal to pivot, pIndex
    // is incremented and that element would be placed before the pivot.
    for (int i = start; i < end; i++)
    {
       
         
        if (a[i].x <= pivot)
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
void  quicksort_comparisions(Point a[] ,int start, int end)
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
void  quicksort(Point a[] ,int n)
{
    
    quicksort_comparisions(a,0,  n-1);

}
/////////////////////////////////////////////////////////////////
//distance between two points
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y)
            );
}
//comparing all points together
float comparingTwoPoints(Point P[], int n)
{
    float min = 10000000;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float ClostestPair( Point P[], int n){
    
    if(n<=3)
    return comparingTwoPoints(P,n);
    
    //we need to sort the array
  quicksort(P , n);
   //divide the array to two halves
   int mid = n/2;
    Point midP = P[mid];
   //find the distance in every half
   
  float d1 = ClostestPair(P, mid);
    float d2 = ClostestPair(P + mid, n - mid);
    //finding the min distance
    float d=d1<d2?d1:d2;
    //------------now we should find the min distance across the two halves--------
    // we need to put the point that are +d, -d from the x axis in an array
        Point strip[n];
    int count = 0;  //to know the size of the array
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midP.x) < d)  //where |x-midpoint<d|,then push in strp array
            strip[count] = P[i], count++;
        // then we need to get the min by comparing the stripArray
        float minAcross=comparingTwoPoints(strip,count);
    //then comparing the result with the d
        float MinDistance=d<minAcross?d:minAcross;
        return MinDistance;
       
}
int main()
{
    Point points[] = {{10, 21}, {15, 3}, {60, 2}, {1, 7}, {5, 9}, {1, 2}};
   
    int n = sizeof(points) / sizeof(points[0]);
    
    cout << "The smallest distance is " << ClostestPair(points, n);
    return 0;
}  
