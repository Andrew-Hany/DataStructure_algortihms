#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

struct output{
string name;
double score;
};
// ---------------------------------------------- //
int Partition(vector<output> &a, int start, int end)
{

	float pivot = a[end].score;

	float pIndex = start;


	for (float i = start; i < end; i++)
	{
       
         
		if (a[i].score <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[end]);

	// return pIndex (index of pivot element)
	return pIndex;
}


void  quicksort_comparisions(vector<output> &a,int start, int end)
{

	if (start >= end)
		return ;


	int pivot = Partition(a, start, end);


	quicksort_comparisions(a, start, pivot - 1);


	quicksort_comparisions(a, pivot + 1, end);

  
}
void quicksort(vector<output> &a ,int n)
{

	quicksort_comparisions(a,0,  n-1);

}





// ---------------------------------------------- //
struct URL{
string name;
double impression;
double ctr;
double clks;
double pr;
double score;
};

//graph

struct Edge{
    string src,dest;
    int srcId;
};
class Graph{
    public:
        vector<vector<string> > adjList;
        vector<Edge> edges;
        vector<string> nodes;
         vector<URL> urls;
         
        Graph(int N){
        adjList.resize(N);

        }
        void addEdge(string src,string dest){
            Edge edge;
            
            //  edge.srcId=srcId;
            int biggestID=0;
            int flag=0;
            
            if(edges.size()==0)
           {
               edge.src=src;
            edge.dest=dest;
            edge.srcId=0;
           }
           else{
            
             for(int i=0;i<edges.size();i++)
                 if(src==edges[i].src)
                     {
                         edge.srcId= edges[i].srcId;
                         flag=1;
                     }
                 else if(biggestID<edges[i].srcId)
                    biggestID=edges[i].srcId;
                    
            if(flag==0)
            edge.srcId=biggestID+1;
                    
            
             edge.src=src;
            edge.dest=dest;
           }
            //  cout<<edge.srcId;
          edges.push_back(edge);
            adjList[edge.srcId].push_back(dest);
        }




        void printGraph()
            {
                for (int i=0; i<adjList.size(); i++)
                {
                    cout <<nodes[i]<<"-->";
                    for (string v: adjList[i])
                        cout<<v<<" ";
                    cout <<endl;
                }

            }
       
};

//------------------------------children_count-----------------------------//
void children_count(Graph g,int childerC[]){
    
    //   int childerC[g.adjList.size()]={0};
        for (int i=0; i<4; i++)
                    {
                        int counter=0;
                        for (string v: g.adjList[i])
                            counter++;
                        childerC[i]=counter;
                        // cout<<counter<<endl;
                            
                        }
}
//------------------------------children_count-----------------------------//

//------------------------------Page Rank-----------------------------//
void PageRank(Graph &g,int childerC[]){
    int size=g.nodes.size();
  vector<double>  Prank(size);
   vector<double> PrankUtil(size);
     for(int i=0;i<size;i++){
         Prank[i]=1.0/double(size);
         PrankUtil[i]=0.0;
     }
   

    
    
    
    //i represents all the edges
    for (int i=0; i<size; i++)//represent all the sources
        for (int j=0; j<g.edges.size(); j++)
        {
            // cout<<i<<" "<<g.edges[j].dest<<endl;
        int index=0;
            if(g.nodes[i]==g.edges[j].dest)
                {
                
                PrankUtil[i]=PrankUtil[i]+(Prank[g.edges[j].srcId]/childerC[g.edges[j].srcId]);
                // Prank[i]=PrankUtil[i];
                // cout<<g.edges[j].dest<<" "<<PrankUtil[i]<<" "<<childerC[g.edges[j].srcId]<<endl;
                    
                }
        
        }
        for (int i=0; i<size; i++){
            Prank[i]=PrankUtil[i];
             g.urls[i].pr=PrankUtil[i];
            PrankUtil[i]=0;
            // cout<<Prank[i]<<endl;
        }

    
    
}
//------------------------------Page Rank-----------------------------//

//-----------------------------Ctr-------------------------------------//
void Ctr(Graph &g,string input){

    ofstream Ctr_file;
    Ctr_file.open("Ctr.txt");
    for(int i=0;i<g.urls.size();i++){
        if(g.urls[i].name==input)
        {
            int clks= g.urls[i].clks+1;
            g.urls[i].ctr=(clks/g.urls[i].impression)*100;
            g.urls[i].clks=clks;
            // cout<<g.urls[i].ctr;

        }
    Ctr_file << g.urls[i].name << ","<<g.urls[i].clks<<","<<g.urls[i].ctr<<endl;
    }

    Ctr_file.close();
}
//-----------------------------Ctr-------------------------------------//
//---------------------------impressions------------------------------//
void impressions(Graph &g,string input){

    ofstream impressions_file;
    impressions_file.open("impression.txt");
    for(int i=0;i<g.urls.size();i++){
        if(g.urls[i].name==input)
        {
           g.urls[i].impression++;

        }
    impressions_file << g.urls[i].name << ","<<g.urls[i].impression<<endl;
    }


   impressions_file.close();
}

//---------------------------impressions------------------------------//
//------------------------------Score-----------------------------//
void score(Graph &g){
    for(int i=0;i<g.nodes.size();i++){
 double temp=(0.1*g.urls[i].impression)/(1+0.1*g.urls[i].impression);
 double temp1=(1-temp)*g.urls[i].pr;
 double temp2=temp*g.urls[i].ctr;
        g.urls[i].score= (0.4*g.urls[i].pr+(temp1+temp2)*0.6);
        // cout<< g.urls[i].score<<endl;
    }

}


//------------------------------Score-----------------------------//

//-------------------------------reading URls to the graph --------------------//
void readURLs( Graph &g){
    ifstream f;
    f.open("Web_Graph.txt");
   if(f.is_open())
   {
        string line;
        int i=0;
        while(getline(f, line))
        {

            stringstream ss(line);
            string src, dest;
            getline(ss,src,','); 
            // cout<<src<<"-> ";
            getline(ss,dest,'\n'); 
            // cout<<dest<<endl;
            g.addEdge(src,dest);
           
            if(g.nodes.size()==0)
             g.nodes.push_back(src);
             else{
            int flags=0;
            int flagd=0;
            for(int j=0;j<g.nodes.size();j++)
                 {
                     if(g.nodes[j]==src)
                    flags=1;
                    if(g.nodes[j]==dest)
                    flagd=1;
                 }


            if(flags==0)
                g.nodes.push_back(src);
             if(flagd==0)
                g.nodes.push_back(dest); 
               
                
     
             }

        }




   }
        f.close();
}

//---------------------------------------reading URls to the graph-----------------------------------------------------//



//-----intialize the struct of URL data---------------------------//

void Url_data(Graph &g)
{

    // string name;
    // float impression;
    URL u;
    for(int i=0;i<g.nodes.size();i++)
    {
        // u.name=g.nodes[i];

    g.urls.resize(g.nodes.size());
    g.urls[i].name=g.nodes[i];
    // cout<<g.urls[i].name;
    }


        ifstream f;
        f.open("impression.txt");

    if(f.is_open())
    {
            string line;
            int i=0;
            while(getline(f, line))
            {

                stringstream ss(line);
                string link, impression;
                getline(ss,link,','); 
                // cout<<src<<"-> ";
                getline(ss,impression,'\n'); 
                // cout<<dest<<endl;
                for(int i=0;i<g.nodes.size();i++)
                        {
                            if(link==g.urls[i].name)
                                {
                                
                                    g.urls[i].impression=stof(impression);
                                }

                        }

            }
    }

    ifstream File;
        File.open("Ctr.txt");
        if(File.is_open())
    {
            string line;
            int i=0;
            while(getline(File, line))
            {

                stringstream ss(line);
                string link2, ctr,clks;
                getline(ss,link2,','); 
       
                getline(ss,clks,',');
                getline(ss,ctr,'\n'); 
         
        
                for(int i=0;i<g.nodes.size();i++)
                        {
                            if(link2==g.urls[i].name)
                                {
                                    g.urls[i].ctr=stof(ctr);
                                     g.urls[i].clks=stof(clks);
                                
                                    
                                }

                        }

            }
    }
    
}
//-----intialize the struct of URL data---------------------------//

//---------------------parsing input--------------------------
vector<string> split(string str)
{

    vector<string> name;
    istringstream ss(str);
    string word;
    if(str[0]=='"'&&str[str.size()-1]=='"')
       { 

        //   str.erase(remove(str.begin(), str.end(), '"'), str.end());

           name.push_back(str);
       
       }
    else {
        while (ss >> word)
            {
                name.push_back(word);
            }
    }
        cout<<endl;
    return name;
}
//---------------------parsing input--------------------------
string make_lowercase( string in )
{
  std::string out;

  std::transform( in.begin(), in.end(), std::back_inserter( out ), ::tolower );
  return out;
}
//-------------------------------------Searching about the key word------------------------//

void KeywordSearch(Graph &g, vector<string> input,   vector<output> &outputs ){
    vector<string> array;
     ifstream f;
      f.open("Key_word.txt");
   if(f.is_open())
   {
        string line;
        int i=0;
         int flagOr=0;
         int url1=0,url2=0;
        while(getline(f, line))
        {

            stringstream ss(line);
            string url,keyword;
           
            getline(ss,url,','); 
          while( getline(ss,keyword,','))
            {
                if(input[0][0]=='"'&&input[0][input[0].size()-1]=='"')
                    {
                        input[0].erase(remove(input[0].begin(), input[0].end(), '"'), input[0].end());
                        if(input[0]== keyword)
                             array.push_back(url);
                    }
                    // transform(option.begin(), option.end(), option.begin(), ::tolower);
                else if ( make_lowercase( input[1] )=="or")
                {
                    if((input[0]== keyword | input[2]== keyword) &&flagOr==0)
                    {
                             array.push_back(url);
                             flagOr=1;
                    }
                }
                else if ( make_lowercase( input[1] )=="and"){
                    
                    if(input[0]== keyword )
                        url1=1;
                    if(input[2]== keyword)
                        url2=1;
                        if(url1==1&&url2==1 &&flagOr==0)
                             {
                                 array.push_back(url);
                                 flagOr=1;
                             }
                }
                else {
                    if((input[0]== keyword | input[1]== keyword) &&flagOr==0)
                    {
                             array.push_back(url);
                             flagOr=1;
                    }
                }
           
            }
        
        flagOr=0;
        url1=0;
        url2=0;
            
        }
   }
        outputs.resize(array.size());
        for(int i=0;i<array.size();i++){
            for(int j=0;j<g.urls.size();j++)
            {
                if(array[i]==g.urls[j].name)
                {
                    outputs[i].name=g.urls[j].name;
                    outputs[i].score=g.urls[j].score;
        
                }
            }

}
   

}
//-------------------------------------Searching about the key word------------------------//
int main()
{
    

    int childerC[4];
    vector<output> outputs;
    // int N=4;
        Graph graph(4);
    
    readURLs(graph); //making the graph 
    Url_data(graph); //filling the data of impresssions and the ctr
    //  cout<<graph.urls[2].name<<" "<<graph.urls[2].ctr;
        //   graph.printGraph();
        children_count(graph,childerC);
        PageRank(graph, childerC);//computing the Page rank
            score(graph);
        cout<<endl;


            string input;
            stringstream ss;
            int choice;
            
            cout<<"Welcome!\n 1)New Search\n 2)Exit\n";
            cin>>choice;
            cin.ignore();
        // -----------searching ------------
    if(choice==2)return 0;

        while(true){
            string input;
            stringstream ss;
            
        cout<<"search bar .... :";
        getline(cin, input);
            ss << input;
            // cout<<input<<endl;
    //         for(int i=0;i<1;i++)
    // cout<<split(input)[i]<<" ";
    // cout<<endl;



    KeywordSearch(graph, split(input),   outputs );
    quicksort(outputs ,outputs.size());

    int counter=0;
    if(outputs.size()==0)
    {
        cout<<"no date found"<<endl;
        cout<<"\nWould you like to \n1)New search\n2) Exit\n";
        cin>>choice;
        if(choice==2)return 0;

    }
    else{
        choice=1;
        while(choice==1){
        cout<<"Search Results:\n";
        counter=0;
    for(int i=outputs.size()-1;i>=0;i--)
    {
        cout<<counter+1<<")"<< outputs[i].name<<endl;
        impressions(graph,outputs[i].name); //update the imoression
        counter++;
    }
    cout<<"\nWould you like to \n1)Choose a webpage to open\n2)New search\n3) Exit\n";
    cin>>choice;
    if(choice==1){


    int userInput;
    
    cout<<"\nenter the link you want to enter"<<endl;
    cin>>userInput;
    while(userInput>outputs.size()){
        cout<<"there is no result such that, please enter again the UrL you want to visit "<<endl;
cin>>userInput;
    }

    string modify_URL_Ctr= outputs[outputs.size()-userInput].name;
    cout<<endl;
    Ctr(graph, modify_URL_Ctr);

    cout<<"now You are viewing "<<outputs[outputs.size()-userInput].name<<endl;
    cout<<"\nWould you like to:\n1)Return to search results\n2)New search\n3)Exit\n";
    // cin.ignore();
    cin>>choice;
    if(choice==3){return 0;}
    // else if(choice==1){
    //     cout<<"Search Results:\n";
    //     counter=0;
    // for(int i=outputs.size()-1;i>=0;i--)
    // {
    //     cout<<counter+1<<")"<< outputs[i].name<<endl;
    //     counter++;
    // }
    // }


    }
    else if(choice==3) {return 0;}


    }
    }
    cin.ignore();
        }
  

return 0;
}
