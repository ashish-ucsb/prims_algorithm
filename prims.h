#ifndef PRIMS_H
#define PRIMS_H
using namespace std;

class Prims
{ 
    int V;
    vector< vector<int> > graph;
    vector< pair <int,int> > edges;
    vector<int> parent;  
    vector<int> key;        
    vector<bool> mstSet;

public:

    Prims(int num_nodes, vector< vector<int> > matrix);
    void printGraph();
    int minKey();
    void primMST(int limit);
    void printEdges();
    
};

#endif