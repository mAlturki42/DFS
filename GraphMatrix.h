/*
	Title:          GraphMatrix.h
	Author:         Mohammed Alturki
	Date Created:   4/23/2021
	Purpose:        GraphMatrix class implementation
*/
#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>

using namespace std;

class GraphMatrix
{
    private:
        int **vertexMatrix;
        int numVertices;
        int numEdges;

    public:
        //constructor with integer as a parameter
        GraphMatrix(int num_vertices)
        {
            numVertices = num_vertices;
            vertexMatrix = new int *[numVertices];

            for (int i = 0; i < numVertices; i++)
            {
                vertexMatrix[i] = new int[numVertices];
            }

            for (int i = 0; i < numVertices; i++)
            {
                for (int k = 0; k < numVertices; k++)
                {
                    vertexMatrix[i][k] = 0;
                }
            }
        }

        //destructor
        ~GraphMatrix()
        {
            for (int i = 0; i < numVertices; i++)
            {
                delete[] vertexMatrix[i];
            }
            delete[] vertexMatrix;
        }

        //to add edge
        void addEdge(int vertex1, int vertext2)
        {
            vertexMatrix[vertex1][vertext2] = 1;
            numEdges += 1;
        }

        //function to print GraphMatrix
        void printGraph()
        {
            for (int i = 0; i < numVertices; i++)
            {
                for (int k = 0; k < numVertices; k++)
                {
                    cout << vertexMatrix[i][k] << "  ";
                }
                cout << endl;
            }
        }

        //function to get the first vertex, instead of 0, to get to all nodes
        int getFirstVertex()
        {
            int first_vertex = 0;
            int findCol = 1;
            for(int j = 0 ; j < numVertices ; j ++)
            {
                int findCol = 1;
                for(int i = 0 ; i < numVertices ; i++)
                {
                    if(vertexMatrix[i][j] == 1)
                    {
                        findCol = 0;
                        break;
                    }
                }
                if(findCol == 1)
                {
                    first_vertex = j;
                    break;
                }
            }
            return first_vertex;
        }

        //function to check if there is an edge return true, false otherwise
        bool isThereAnEdge(int row, int column)
        {
            if (vertexMatrix[row][column] == 1)
                return true;
            
            else
                return false;
        }
};

#endif
