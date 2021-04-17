#include <vector>
#include <iostream>
#include <unordered_map>
#include"disjoint_set.cpp"
using namespace std;



//graph
struct Edge{
	int src,dest;
};
class Graph{
	public:
		vector<vector<int> > adjList;
		vector<Edge> edges;
        Graph(int N){
        adjList.resize(N);

        }
        void addEdge(int src,int dest ){
            Edge edge;
            edge.src=src;
            edge.dest=dest;
            
            edges.push_back(edge);
            // cout<<edges[0].dest;
            adjList[src].push_back(dest);
        }




        void printGraph()
            {
                for (int i=0; i<adjList.size(); i++)
                {
                    cout <<i<<"-->";
                    for (int v: adjList[i])
                        cout<<v<<" ";
                    cout <<endl;
                }

            }
        bool isCycle(){
        DisjointSet ds;
        vector<int> universe ;
        for(int i=0;i<edges.size();i++)
                universe.push_back(edges[i].src);
                universe.push_back(edges[edges.size()-1].dest);
        ds.makeSet(universe);
        // cout<<edges.size();
                for(int i=0;i<edges.size();i++)
                {
                    cout<<edges[i].dest<<endl;
                int x= ds.Find(edges[i].src);
                int y =ds.Find(edges[i].dest);
                cout<<x<<y<<endl;
                if(x==y)
                return 1;
                ds.Union(edges[i].src,edges[i].dest);
                }
        // printSets(universe, ds);
        // cout<<endl;
        return 0;

        }
    
};



int main()
{
   
   
int N=6;
	Graph graph(6);
	graph.addEdge(0,1);
		graph.addEdge(1,2);
			graph.addEdge(2,3);
					graph.addEdge(3,4);
					graph.addEdge(4,5);
						graph.addEdge(5,0);
	graph.printGraph();
 if(graph.isCycle()) cout<<"yes";else cout<<"no";
	return 0;
}
