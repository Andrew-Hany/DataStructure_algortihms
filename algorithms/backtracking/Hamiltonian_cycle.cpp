#include <iostream>
#include <vector>
using namespace std;
  //NOTE : read the comments which reveal our logic

bool canAdded(int v,vector<vector< bool>>grid,
             vector<int>&p, int cur)
{
   // checking if there is a connection or not between the vertix v and the cur ver,
   //if not so it can not be add to the path array
    if (grid [p[cur - 1]][ v ] == 0)
        return false;
  
   // also there is no vertixcan be repeated if it is not the last vertix (to be the same as the first to be in a cycle )
    for (int i = 0; i < cur; i++)
        if (p[i] == v)
            return false;
  
    return true;
}
  

bool backtracking(vector<vector< bool>>grid,
                   vector<int>&p, int cur)
{
  
    if (cur == grid.size())  //base case
    {
        //when reaching the last vertix we shoud see it is connnected to the first vertex or not
        if (grid[p[cur - 1]][p[0]] == 1)
            return true;
        else
            return false;
    }
  
    //looping over the vertices we have
    for (int v = 1; v < grid.size(); v++)
    {
      
        if (canAdded(v, grid, p, cur))
        {
            p[cur] = v;  // if it can be add then push inside the path array
  
         
            if (backtracking (grid, p, cur + 1) == true)  // check the next one if it is also true
                return true; //if it is true we wont backtracking, if it fails remove the vertix from the array
  
          
            p[cur] = -1;   // here,  if cur+1 fails then return back to the previous place to check other available paths
        }
    }
  
   
    return false;
}
 
 //calling the other functions inside this function
bool Hamiltonian(vector<vector< bool>>graph)
{
    vector<int>path(graph.size());
    for (int i = 0; i < graph.size(); i++)
        path[i] = -1;   // intializing a dynamic array to know the path and used it in the


    path[0] = 0;
    if (backtracking(graph, path, 1) == false ) // if this return false there is no  Hamiltonian
    {
        cout << "\nIn the given graoh, There is no solutin exists";
        return false;
    }
  
   cout << "One possibility is as follows:"<<
            " \n";
    for (int i = 0; i < graph.size(); i++)
        cout << path[i] << " ";
 
    cout << path[0] << " ";  // printing the first one again
    cout << endl;
    return true;
}
  

 
  

int main()
{
  
  vector<vector< bool>>graph1={{0, 1, 0, 1, 0},
                                {1, 0, 1, 1, 1},
                                {0, 1, 0, 0, 1},
                                {1, 1, 0, 0, 1},
                                {0, 1, 1, 1, 0}};
   
    Hamiltonian(graph1);
  
    return 0;
} 
