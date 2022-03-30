/*
	Title:          Graph.cpp
	Author:         Mohammed Alturki
	Date Created:   4/23/2021
	Purpose:        Driver for a GraphList and GraphMatrix using the DFS, and reading vertices and edges from file
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GraphList.h"
#include "GraphMatrix.h"
#include "Stack.h"

using namespace std;


int main()
{
    ifstream inFile;
    string file_name;
    int numVertices;
    int vertex1, vertex2;
    int s;
    bool is_cyclic = false;
    Stack<int> stack;
    bool *visited = new bool[numVertices];
    bool start = false;
    int currentV;


    cout << "Enter the name of your file that contains the graph vertices:\t";
    getline(cin, file_name);

    inFile.open(file_name);
    if (!inFile)
    {
        cout << "The file you entered could not be opened" << endl;
    }

    //reading the number of vertices from the file
    inFile >> numVertices;

    //creating a GraphMatrix and GraphList objects 
    GraphMatrix graph_matrix(numVertices);
    GraphList graph_list(numVertices);

    //calling and storing first vertex value in first variable
    int first = graph_matrix.getFirstVertex();

    //reading vertices and adding edges
    while (inFile >> vertex1)
    {
        inFile >> vertex2;

        graph_matrix.addEdge(vertex1, vertex2);
        graph_list.addEdge(vertex1, vertex2);
    }

    //printing adjacency matrix
    cout << "\n\nAdjacency matrix:\n";
    graph_matrix.printGraph();

    //printing adjacency list
    cout << "\n\nAdjacency list...\n";
    graph_list.printGraph();

    //traversing using DFS
    cout << "\n\nNow traversing & printing graph vertices with DFS.\n\n\n";

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    //pushing then printing first vertex
    stack.push(first);
    cout << first << "\t";

    while (!stack.isEmpty())
    {
        stack.peek(currentV);
        if (!visited[currentV])
        {
            visited[currentV] = true;
        }
        for (int i = 0; i < numVertices || start == true; i++)
        {
            if (start == true)
            {
                i = 0;
                start = false;
            }
            if (graph_matrix.isThereAnEdge(currentV, i) && visited[i] == false)
            {
                stack.push(i);
                visited[i] = true;
                cout << i << "\t";
                currentV = i;
                start = true;
            }
            //if there is a cycle:
            if (graph_matrix.isThereAnEdge(currentV, i) && visited[i] == true && stack.find(i))
            {
                cout << "\n\n\nAh shooty pooty.  This graph has a cycle.	\n";
                is_cyclic = true;
            }
        }

        stack.pop(currentV);
    }
    cout << endl;

    inFile.close();

    return 0;
}
