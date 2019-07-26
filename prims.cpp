#include<iostream> 
#include<climits>
#include<vector>
#include <bits/stdc++.h>
using namespace std; 
#include "prims.h"

Prims::Prims(int num_nodes, vector< vector<int> > matrix) 
{ 
    V = num_nodes;
    graph = matrix;
    for (int i = 0; i < V; i++)
        key.push_back(INT_MAX), mstSet.push_back(false), parent.push_back(-1);
    key[0] = 0;  
    parent[0] = -1;
    // cout << "constructor" << key[0] << parent[0] << mstSet[0] << endl;
    // cout << V << graph[0][0] << endl;
}

int Prims::minKey()  
{   
    int min = INT_MAX, min_index;  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;
    return min_index;  
}  

void Prims::primMST(int limit)
{
    int count = 0;
    while(count <= limit)
    { 
        int u = minKey(); 
        mstSet[u] = true; 
        edges.push_back(make_pair(parent[u], u));
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v];
        count++; 
    }
}

void Prims::printEdges() 
{
    for (int i=1; i<edges.size(); i++)
        cout << edges[i].first << " " << edges[i].second << endl;
}

void Prims::printGraph()
{
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}