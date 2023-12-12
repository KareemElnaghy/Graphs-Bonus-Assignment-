//Kareem Elnaghy
//ID: 900223587

#include <iostream>
#include "Graphs.h"
using namespace std;

void displaySample(Graphs Cities, string filename);

int main() {

    Graphs c;
    displaySample(c, "Test.txt");

}

void displaySample(Graphs Cities, string filename)
{
    cout<<"File: "<<filename<<endl;

    Cities.getGraph(filename);

    cout<<"Number of Verticies = "<<Cities.No_of_Verices()<<endl;
    cout<<"Number of Edges = "<<Cities.No_of_Edges()<<endl<<endl;

    Cities.dispGraph();
    cout<<endl;

    Cities.dispEdges();
    cout<<endl;

    int sourceVertex = 0;

   Cities.shPath(sourceVertex);

  //Cities.DFS();
}
