/*
	Title:    GraphList.h
	Author:   Mohammed Alturki
	Date:     4/23/2021
	Purpose:  Header file for graph list class with add edge and print graph
*/
#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
using namespace std;

class GraphList
{
    private:
        // structure for the node of the list
        struct ListNode
        {
            int vertex;
            ListNode *next;
        };

        // pointer to hold the base address of array of linked lists
        ListNode **headArray;

        // data member to hold the number of vertices
        int numVertices;

        // data member to hold the number of edges
        int numEdges;

    public:
        // constructor - accepts an integer
        GraphList(int vertices)
        {
            // sets the private attribute numVertices
            numVertices = vertices;

            numEdges = 0;

            // dynamically allocates an array of pointers to ListNodes
            headArray = new ListNode *[numVertices];

            // initialize all the head pointer to NULL
            for (int i = 0; i < numVertices; i++)
            {
                headArray[i] = NULL;
            }
        }

        void addEdge(int source, int destination)
        {
            ListNode *newNode = new ListNode;
            newNode->vertex = destination;
            newNode->next = NULL;

            ListNode *nodePtr = headArray[source];

            // update headArray to point to new node
            if (nodePtr == NULL)
            {
                headArray[source] = newNode;
            }
            else
            {
                while (nodePtr->next != NULL)
                {
                    nodePtr = nodePtr->next;
                }
                nodePtr->next = newNode;
            }
            numEdges++;
        }

        // Destructor
        ~GraphList()
        {
            // delete each linked list
            for (int i = 0; i < numVertices; i++)
            {
                delete headArray[i];
            }
            delete headArray;
        }

        // this function print the graph, one linked list at a time
        void printGraph()
        {
            // store the head
            ListNode *ptr;
            for (int i = 0; i < numVertices; i++)
            {
                ptr = headArray[i];
                // print the vertex
                cout << i << "--->";

                // print its neighboring vertices
                while (ptr != NULL)
                {
                    cout << ptr->vertex << "--->";
                    ptr = ptr->next;
                }
                cout << "NULL" << endl;
            }
        }
};

#endif