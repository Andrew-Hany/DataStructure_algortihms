#include<iostream>
#include<vector>
#include <unordered_set>

#include"directed_graph.cpp"
#define infi 1000000000 
using namespace std;


template <class X>
void Graph<X>::Dikstra(X s){

int dist[v.size()]; // the distance from the source Vertix to the other verticies
bool visited[v.size()];//if visted 
int Startindex=getindex(s);//the index where the first vertix locate
path.resize(v.size());  // the path 

//------------intialing ----------------
for (int i = 0; i < v.size(); i++) { 
		visited[i] = false; 
		path[i] = -1; 
		dist[i] = infi; 
	} 

dist[Startindex] = 0;  // the fist vertec has distance =0
path[Startindex] = -1;  // indicates there is no path
X currentVertix=s; // the current vertix
int currentindex=getindex(s);


//------------intialing ----------------
for (int k = 0; k < v.size(); k++) 
{
    visited[k] = true; 
 
		for (int i = 0;i< v[k]->children.size();i++) { 
			int Vindex = getindex(v[k]->children[i].first);   //index of the children of the Vertix
            X V=v[k]->children[i].first; // the source vertex
      
	
			int Dis= dist[k]+ v[k]->children[i].second; // distance equals = distance if the current vertex +the distance to the other vertex
			if (Dis < dist[Vindex]) { //comparing the dis where just computed with the  previous value to 
				dist[Vindex] = Dis;   //check the shortest 
				path[Vindex] = v[k]->vertix; 
			} 
		} 
      
        // cout<<endl;
        }

        for (int i = 0;i<v.size();i++) { 
            cout<<dist[i]<<" ";
        }
        cout<<endl;
        for (int i = 0;i<v.size();i++) { 
            cout<<v[i]->vertix<<" ";
        }
        cout<<endl;
        for (int i = 0;i<v.size();i++) { 
            cout<<path[i]<<" ";
        }
      
}

template <class X>
int Graph<X>::Getpath(X s, X e) //print the path and return the count of the edges
{
    if(e!=-1)
        cout<<e;
  int count=0;
    while(s!=e)
    {
        
        if(e==-1)
        cout<<"no path found"<<endl;

        else{
            // cout<<i;
            
          e=path[getindex(e)];
          cout<<"->"<<e;
          count++;
            
        }
    }
     cout<<endl;
return  count;
}


int main()
{

///-------test case 1----------
    // Graph<char> g;
    //  g.addedge('A', 'B', 1);
    // g.addedge('A', 'D', 12);
    // g.addedge('A', 'F', 16);
    // g.addedge('B', 'C', 1);
    // g.addedge('B', 'D', 10);
    // g.addedge('B', 'E', 11);
    // g.addedge('B', 'F', 14);
    // g.addedge('C', 'D', 9);
    // g.addedge('D', 'E', 1);
    // g.addedge('D', 'F', 1);
    //  g.Dikstra('A');
    //   g.Getpath('A','F');
///-------test case 2----------
       Graph<int> g;
    g.addedge(0, 1, 1);
    g.addedge(0, 2, 4);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 6);
    g.addedge(2, 3, 3);
     cout<<endl;
    g.Dikstra(0);
    // cout<<endl;
    // g.display();
    //  cout<<endl;
      cout<<"Nom. of edges to reach the destination = "<<g.Getpath(0,3)<<endl;
///-------test case 2----------

return 0;
}
