#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph
{
public:

    vector<vector<int>> adjList;
    Graph(vector<Edge> const& edges, int N)
    {
        adjList.resize(N);
        for (auto& edge : edges)
        {
            adjList[edge.dest].push_back(edge.src);
        }

    }

    };

void DFS(Graph & graph, int v, bool visited[], vector<int> &finished)
{
    visited[v] = true;
    cout<<v<<" ";


    for (int e : graph.adjList[v])
    {
        if (!visited[e])
            DFS(graph, e, visited, finished);
    }

    finished.push_back(v);
}

void transpose(vector <Edge> &edges, Graph &graph)
{
    for (auto& edge : edges)
    {
        int temp = edge.dest;
        edge.dest = edge.src;
        edge.src = temp;
    }
    Graph transposegraph(edges, edges.size());
    graph = transposegraph;
}
void get_groups(Graph &graph, vector<Edge> &edges )
{

    bool visited[edges.size()];
    vector<int> finished;


    //then do DFS for every edge
    for (int i = 0; i < edges.size(); i++)
        if (visited[i] == false)

            DFS(graph, i, visited, finished);
                

    //then we need to tanspose the whole Graph
    transpose(edges, graph);
    //re intialize the visted by zeros again
    for (int i = 0; i < edges.size(); i++)
    {
        visited[i] = false;
    }
 cout<<endl;
    
    for(int i=finished.size()-3;i>=0;i--)
    {
     
        if (visited[finished[i]])
        finished.pop_back();
        else

        {
           
            cout << "Group"  << ": { ";
        DFS(graph, finished[i], visited, finished);//this should get the groups
            cout << " }" << endl;
        }
    }


    
    
    
    
}

int main()
{
    

       vector<Edge> edges =
    {
     {0, 1}, {1,2},{2,0},{2,3},{3,4}, {4,5},{5,6}, {6,3},
        {7,6}, {7,8}, {8,9}, {9,10}, {10,7}, {10,11}
    };
    Graph graph(edges, edges.size());
    get_groups(graph,edges);


    return 0;
}
