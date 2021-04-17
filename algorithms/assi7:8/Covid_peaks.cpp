/******************************************************************************

                              Online C++ Compilearr.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include<vector>

using namespace std;


int Covid_Peaks(vector<int>cases){
    int sum=0;
    int sum2=0;
    int sumflag=0;
    

    for(int i=0;i<cases.size()-1;i++){
        
        // first i need to decide if it will sum the follwing or not 
        //so i need to see if the today's cases is more than yesterday, then make the flag =1
        if(cases[i]>cases[i-1] )
            sumflag=1;
            
        // if the flag == 1, and there are repeated number  of cases , they will be summed     
        if(cases[i]==cases[i+1] &&sumflag==1)
          {
              sum++;
            //   cout<<cases[i]<<" ";
          }
          // this handled two things
          //1) checking if the today's number of cases are greater than tommorrows and the flag==1, 
             //then add 1 to the sum and give it to to sum2 and re-intialize the sum and the falg by zero 
          //2) if there is a peak lasts for one day ( i calculated it also ), as the sum will be zero 
            // and will be incremented and then added to the sum2
        else if(cases[i]>cases[i+1]&&sumflag==1)
          {
              sum++;
              sum2=sum2+sum;
              sumflag=0;
              sum=0;
          }
         else {sum=0;sumflag=0;}
    // cout<<sum<<" "<<sum2<<" " <<cases[i]<<" "<<endl;
    }
  
    return sum2;
}
int main()
{
vector<int>cases={3, 5, 20, 20, 20, 19, 18, 19, 20, 21, 21};
cout<<"Total number of days the cases remained at the maximum of their respective waves = "<<Covid_Peaks(cases)<<endl;
}
