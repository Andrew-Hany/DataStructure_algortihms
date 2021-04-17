#include <iostream>

using namespace std;

int  maxp(int arr[],int n){
    int sum=0;
    int index1=0,index2=0,temp1=0,temp2=0;
    int max=0;
    for(int i=0;i<n;i++){
       temp2=i;
        sum+=arr[i];
        if(max<=sum)
       {
           index1=temp1;
           index2=temp2;
           max=sum;
           
       }
        
        if(sum<0){
            temp1=i+1;
            sum=0;
        }
    }
    cout<<index1<<" "<<index2<<" "<<endl;
    return max;
}

int main()
{
    int arr[5]={1,4,-6,8,6};
cout<<maxp( arr,5);
    return 0;
}