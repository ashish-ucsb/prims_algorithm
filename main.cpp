#include<iostream> 
#include <sstream>
// #include<climits>
#include<vector>
#include <string>
#include <bits/stdc++.h>
using namespace std; 
#include "prims.h"

int main(int argc, char* argv[]) 
{
	int num_nodes;
	cin >> num_nodes;

	// second, read in the complete graph
	vector< vector<int> > graph;
	for(int i=0; i<num_nodes; ++i) {
	  vector<int> row;
	  for (int j=0; j<num_nodes; ++j) {
	    int cost;
	    cin >> cost;
	    row.push_back(cost);
	  }
	  graph.push_back(row);
	}

	// last bit until newline from last cin followed by a blank line
	string skip;
	getline(cin, skip);
	getline(cin, skip);

	Prims p(num_nodes, graph);
	p.primMST(4);
	p.printEdges();
} 