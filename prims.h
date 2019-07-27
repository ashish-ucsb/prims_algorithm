#ifndef PRIMS_H
#define PRIMS_H
using namespace std;

class Prims
{ 
    int V;
    vector<int> parent;  
    vector<int> key;        
    vector<bool> mstSet;
    set<int> s;
    vector< pair <int,int> > edges;

public:

    Prims(int num_nodes);
    int minKey(vector<int> key, vector<bool> mstSet);
    bool checkCycle(int a, int b);
    void primMST(vector< vector<int> > matrix, int limit);
    void printEdges();
    
};

#endif