
#include <iostream>
#include <vector>

using namespace std;
int Meals_calc(vector<int>calories, int allowence_callory ){
    int arr[calories.size()][allowence_callory+1];
    
    for(int i=0;i<calories.size();i++)
        arr[i][0]=1;
        
     for(int i=0;i<calories.size();i++){
         for(int j=0;j<allowence_callory+1;j++){
             if(i==0)
                { 
                    // cout<<calories[i]<<" "<<j<<endl;
                    if(j%calories[i]==0)
                 arr[i][j]=1;
                 else 
                     arr[i][j]=0;
                }
             else if(calories[i]>j)
             arr[i][j]=arr[i-1][j];
             else
             arr[i][j]=arr[i-1][j]+arr[i][j-calories[i]];
             
         }
     }
  
     return arr[calories.size()-1][allowence_callory];
}
int main()
{
vector<int>calories={200, 500, 300, 600};
cout<<"you have  '"<<Meals_calc(calories, 1000 )<<"' options";
    return 0;
}
