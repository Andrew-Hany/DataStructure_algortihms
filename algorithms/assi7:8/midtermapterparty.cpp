#include <iostream>

using namespace std;

void count(int Grid[][5], int rows, int cols){
    int count=0;
    for(int i=0;i<rows;i++)
     for(int j=0;j<cols;j++)
         if(Grid[i-1][j+1]!=1&&Grid[i][j-1]!=1&&Grid[i-1][j]!=1&&Grid[i][j]==1)
         {
            //  cout<<Grid[i][j-1]<<" "<<Grid[i-1][j]<<" "<<i<<" "<<j<<" ";
             count++;
             cout<<endl;
         }
    cout<<count;
}

int main()
{
  
// int Grid[5][8] =
// 	{ 0, 0, 0, 0, 0, 0, 0, 0,
// 	  0, 1, 1, 1, 1, 0, 0, 0,
// 	  0, 1, 0, 1, 0, 0, 1, 0,
// 	  0, 1, 1, 1, 1, 0, 1, 0,
// 	  0, 0, 0, 0, 0, 0, 0, 0, };

//i ignored the blue X here in my grid but it is supposed to be 1's and i dont loop over them
	 int Grid[3][5] = 
	  	{0,0,0,0,0,
	  	 0,0,0,1,0,
         0,1,1,0,0 };
	count(Grid,3,4);
    return 0;
}