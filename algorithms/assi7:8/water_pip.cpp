#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//------------------------------------------//

int waterPip(vector<int>lengths){
     priority_queue<int, vector<int>,greater<int>> priorityQ;
           int Total=0;
           for(int i=0;i<lengths.size();i++)
                priorityQ.push(lengths[i]);
           
           
           while (priorityQ.size()>1){
               int first=priorityQ.top();priorityQ.pop();
               int second=priorityQ.top();priorityQ.pop();
               int sum=first+second;
               Total=Total+sum;
               priorityQ.push(sum);
           }
          return Total;
}
int main()
{

vector<int>lengths={8,3,5,6,2};

cout<<"The  minimum cost of joining the pipes = "<<waterPip(lengths)<<endl;

}
