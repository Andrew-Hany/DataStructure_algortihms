
#include<iostream>
#include<string>
using namespace std; 
  

int findMinLength(string arr[], int n) 
{ 
    int min = 23456234; 
  
    for (int i=0; i<=n-1; i++) 
        if (arr[i].length() < min) 
            min = arr[i].length(); 
    return(min); 
} 
  
bool allContainsPrefix(string arr[], int n, string str, 
                       int start, int end) 
{ 
    for (int i=0; i<=n-1; i++) 
        for (int j=start; j<=end; j++) 
            if (arr[i][j] != str[j]) 
                return (false); 
    return (true); 
}

string commonPrefix(string arr[], int n){
    int index = findMinLength( arr,  n);
    string prefix;

    int low=0,high=index;

    while(low<=high)
    {
        int mid=(low+high)/2; //divding it to small parts

        if(allContainsPrefix( arr,  n, arr[0], low, mid))
        {
            prefix=prefix+arr[0].substr(low, mid-low+1);
            low=mid+1; // if ge is right then check gee if gee right check geek
        }

        else high=mid-1; //if ge is wrong check g is right or not 
    }
    return prefix;
}

int main() 
{ 
    string arr[] = {"Apple", "App", 
                    "Apple_dadas", "Apple"}; 
    int n = sizeof (arr) / sizeof (arr[0]); 
  
    string res = commonPrefix(arr, n); 
  
    if (res.length()) 
        cout << "The longest common prefix is "
             << res<<endl; 
    else
        cout << "There is no common prefix"<<endl; 
    return (0); 
}