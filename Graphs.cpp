// FILE: graphs.cpp
// Graph Library Implementation File for Asn 6

#include <fstream>		// For reading file from disk
#include <iostream>
#include <string>		// For file name
#include <iomanip>
#include "Edge.h"		// Deinition of an Edge

using namespace std;

// Constructor
Graphs::Graphs()
{
	E = V = order = 0;
}

// Destructor
Graphs::~Graphs()
{
}


// Map vertex number (0,1,2,..) to (A,B,C,..)
char Graphs::Vname(const int s) const
{
	return char(s+65);
}

// Get Graph from text File (file name is stored in string fname)
// Graph is stored in adjacency matrix
void Graphs::getGraph(string fname)
{
    ifstream file;
    string line;

    file.open(fname);
    // Local data ...
    weightType wi;

    // Read no. of verices (V)
    if(getline(file, line))
    {
        istringstream iss(line);
        string x;

        while(iss >> x)
        {
            V++;
        }
    }
    file.close();
    // Input weights from the file into a 2-D adjacency matrix of V rows and V columns
    file.open(fname);
    for (int r = 0; r < V; r++) {
        for (int c = 0; c < V; c++) {
            file >> AdjMatrix[r][c];
        }
    }

    // Close the file
    file.close();
    getEdges(); //stores the edges in an array

}

// Display Adjacency Matrix
void Graphs::dispGraph() const
{
	int i,j;
	cout<<"Adjacency Matrix\n";
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
			cout<< setw(3)<< AdjMatrix[i][j] << " ";
		cout<< endl;
	}
}

// Get Non-Zero edges from adjacency matrix
// and store them in array edges[].
void Graphs::getEdges()
{
	int r , c;
	int i = 0;
	weightType weight;

	// Only examine weights above the diagonal
	for (r = 0; r <= V-2; r++)
		for (c = r+1; c <= V-1; c++)
		{
			weight = AdjMatrix[r][c];
			if (weight > 0)
			{
				// save (r,c,weight) in edges[i]
				edges[i].u = r;
				edges[i].v = c;
				edges[i].w = weight;
				i++;
			}
		}

	E = i;		// Number of non-zero edges

}

// Get number of vertices (V)
int Graphs::No_of_Verices() const
{
	return V;
}

// Get Number of Non-zero edges (E)
int Graphs::No_of_Edges() const
{
	return E;
}

// Output an edge (e): Vertex names and weight
void Graphs::printEdge(Edge e) const
{
	cout << Vname(e.u) << " " << Vname(e.v) << " " << e.w << endl;
}

// Display Graph Edges
void Graphs::dispEdges() const
{
	cout<<"Graph Edges\n";
	for (int i = 0; i < E; i++)
		printEdge(edges[i]);
}

// Shortest paths from node s
// uses Dijkstra's Algorithm
void Graphs::shPath(int s)
{
    int i,j;
// Initialization: Set initial values for distance[], processed[], and via[] arrays
    for(i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        processed[i] = 0;
        via[i] = -1;
    }
// Set the distance of the source vertex to itself to 0
        distance[s] = 0;
// Iterate through V-1 vertices (excluding the source)
    for(i = 0; i < V-1; i++)
    {
        int index;
        int minDist = INT_MAX;
        // Find the vertex with the minimum distance among unprocessed vertices
        for(j=0; j < V; j++)
        {
            if(distance[j]<= minDist && !processed[j] )
            {
                minDist = distance[j];
                index = j;
            }
        }
        processed[index] = 1;  // Mark the selected vertex as processed

        // Update distance[] and via[] for adjacent vertices
        for(j = 0; j<V; j++)
        {
            // Relaxation step: Update distance[j] and via[j] if a shorter path is found
            if(AdjMatrix[index][j] && distance[index] != INT_MAX && !processed[j])
            {
                if(distance[index] + AdjMatrix[index][j] < distance[j])
                {
                    distance[j] = distance[index] + AdjMatrix[index][j];
                    via[j] = index; // Update the predecessor of vertex j
                }
            }

        }
    }

    cout << "Shortest Paths from Node " << Vname(s)<<endl;
    for (i = 0; i < V; i++) {
        cout << distance[i]<<" ";
        printPath(s, i);
        cout<<endl;
    }
}

// Print path (vertex names) from source (s) to destination (i)
void Graphs::printPath(int s, int i) const
{
    if (via[i] != -1)
        printPath(s, via[i]);
    cout << Vname(i) << " ";
}

// Node Visit Function
void Graphs::visit(int k)
{
    int i;
	order++;
    processed[k] = true;
    val[k] = order;

    for(i = 0; i<V; i++)
    {
        if(AdjMatrix[k][i] > 0 && !processed[i])
            visit(i);
    }
}

// Depth First Search Visit Function
void Graphs::dfsVisit(int vertex) {

    // Mark the current vertex as processed
    processed[vertex] = 1;

    // Explore neighbors of the current vertex
    for (int neighbor = 0; neighbor < V; ++neighbor) {
        // Check if the neighbor is not processed and there is an edge between the current vertex and the neighbor
        if (!processed[neighbor] && AdjMatrix[vertex][neighbor] != 0) {
            // Recursively visit the unprocessed neighbor
            dfsVisit(neighbor);
        }
    }

    // Update the order of visit for the current vertex
    val[order++] = vertex;
}

// Depth First Search Traversal
void Graphs::DFS()
{
    order = 0;

    // Loop through vertices
    for (int i = 0; i < V; i++) {
        if (!processed[i]) {
            dfsVisit(i);
        }
    }

    cout << "DFS Traversal" << endl;
    for (int i = V-1; i >= 0; i--)
        cout << Vname(val[i]) << " ";
}
