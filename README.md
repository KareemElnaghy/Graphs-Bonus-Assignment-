# Graphs Library

## Overview
This C++ library provides functionalities to work with weighted undirected graphs. It supports operations like loading a graph from a text file, displaying the adjacency matrix, traversing the graph using Depth First Search (DFS), and computing shortest paths using Dijkstra's Algorithm.

## Contents
1. **Graphs.h:** Header file containing the declaration of the Graphs class along with function prototypes.
2. **Graphs.cpp:** Source file containing the implementation of the functions declared in Graphs.h.
3. **Edge.h:** Header file defining the Edge class used to model edges in the graph.

## Functionality
- **Map Vertex Name:** Maps vertex numbers to character names.
- **Get Graph:** Loads the graph from a text file in the form of an adjacency matrix.
- **Display Adjacency Matrix:** Displays the adjacency matrix of the graph.
- **Number of Vertices:** Returns the number of vertices in the graph.
- **Number of Edges:** Returns the number of non-zero edges in the graph.
- **Display Edges:** Displays the edges of the graph.
- **Depth First Search (DFS):** Traverses the graph using Depth First Search algorithm.
- **Shortest Paths:** Computes shortest paths from a given source node to all other nodes using Dijkstra's Algorithm.

## Usage
1. Include Graphs.h header file in your C++ program.
2. Create a Graphs object.
3. Use the provided member functions to perform operations on the graph.

## Example
```cpp
#include <iostream>
#include "Graphs.h"
using namespace std;

int main() {
    Graphs g;
    g.getGraph("SampleGraph.txt");
    cout << "Number of Vertices: " << g.No_of_Verices() << endl;
    cout << "Number of Edges: " << g.No_of_Edges() << endl;
    g.dispGraph();
    g.DFS();
    return 0;
}
