#include<iostream> 
#include<climits>
#include<vector>
#include <bits/stdc++.h>
using namespace std; 
#include "prims.h"

Prims::Prims(int num_nodes) 
{ 
    V = num_nodes;
    s = {-1, 0};
}

int Prims::minKey(vector<int> key, vector<bool> mstSet)  
{   
    int min = INT_MAX, min_index;  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;
    return min_index;  
} 

bool Prims::checkCycle(int a, int b)
{
    if (s.count(a) > 0 && s.count(b) > 0)
        return true;
    else
        return false;
} 

void Prims::primMST(vector< vector<int> > matrix, int limit)
{
    parent.clear();
    key.clear();
    mstSet.clear();

    vector< vector<int> > graph = matrix;

    for (int i = 0; i < V; i++)
        key.push_back(INT_MAX), mstSet.push_back(false), parent.push_back(-1);

    key[0] = 0;  
    parent[0] = -1;
    
    int count = 0;
    while(count < limit)
    { 
        int u = minKey(key, mstSet); 
        mstSet[u] = true;
        if (checkCycle(parent[u], u) == false)
        {
            edges.push_back(make_pair(parent[u], u));
            s.insert(parent[u]);
            s.insert(u);
            count++;
        } 
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    }
}

void Prims::printEdges() 
{
    for (int i=0; i<edges.size(); i++)
        cout << edges[i].first << " " << edges[i].second << endl;
}