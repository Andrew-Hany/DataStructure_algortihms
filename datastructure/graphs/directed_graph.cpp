#include<iostream>
#include<vector>
#include <unordered_set>
// #include<bits/stdc++.h> 
#define infi 1000000000 
using namespace std;
template <class X>
class node{
    public:
    
    X vertix;
    vector<pair<X, int> >children;// contains the destinations and the distance to them 
    node(X vertix){
        this->vertix=vertix;
    }
    
      void add_child(X vNumber, int length) 
    { 
        pair<X, int> p; 
        p.first = vNumber; 
        p.second = length; 
        children.push_back(p); 
    } 

};


//---------------------//
template <class X>
class Graph{
    public:
    vector<node<X>* > v;
    vector<X> path;
    Graph(){v.resize(0);}
    void addnode(X sourceVertix, X dest, int dis);
    void addedge(X sourceVertix, X dest, int dis);
    void display();
    int getindex(X vertix);
    void Dikstra(X startvertix);
    int Getpath(X s, X e);


};
template <class X>
void Graph<X>::addnode(X sourceVertix, X dest, int dis){
    int flag=1;
    node<X>* a = new node<X>(sourceVertix);
    v.push_back(a);
    v[v.size()-1]->add_child(dest, dis); 
       
       
           
}
template <class X>
void Graph<X>::addedge(X sourceVertix, X dest, int dis)
    {  
        int flag=0,flag2=1;
        for(int i=0;i<v.size();i++)
            if(v[i]->vertix==sourceVertix)
                {
                    flag=1;
                    v[i]->add_child(dest, dis); 
                }
                    
            if(flag==0)
            {
                    addnode(sourceVertix,dest, dis);
                    
            }

            for(int i=0;i<v.size();i++)
                            if(v[i]->vertix==dest)
                                    flag2=0;
                            
            if(flag2==1){
                node<X>* as = new node<X>(dest);
                  v.push_back(as);
                //    v[v.size()-1]->add_child(dest, 0); 
            }
                

     }
template <class X>
void Graph<X>::display()
    {

     for(int i=0;i<v.size();i++)
        { 
            
             if(v[i]->children.size()>0)
            { cout<<v[i]->vertix;
                for(int j=0;j<v[i]->children.size();j++)
                 cout<<"->"<<v[i]->children[j].first;
            cout<<endl;
            }
        }
    }
template <class X>
int Graph<X>::getindex(X vertix)
{
    for (int i = 0; i < v.size(); i++) 
    { 
        if(v[i]->vertix==vertix)
        return i;
    }
    return 0;
}

