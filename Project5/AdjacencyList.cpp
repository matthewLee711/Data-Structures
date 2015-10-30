#include <iostream>
#include "AdjacencyList.h"

//constructor for adjacency list
AdjacencyList::AdjacencyList()
{

}

//This function will create the adjacency list nodes whenever a new word is passed
AdjacencyList::adjacencyListNode* AdjacencyList::createAdjacencyListNode(int dest)
{
	//create newNode when new word is reached
	adjacencyListNode* newNode = (adjacencyListNode*) malloc(sizeof(adjacencyListNode));
	newNode->destination = dest; // store dest in destination
	newNode->next = NULL;
	newNode->previous = NULL;

	return newNode;	
}

//This function creates a graph of the vertities
AdjacencyList::adjacencyListGraph* AdjacencyList::createGraph(int verticies)
{
	//allocate/create graph
	adjacencyListGraph* newGraph = (adjacencyListGraph*)malloc(sizeof(adjacencyListGraph));
	newGraph->verticies = verticies;//store verticies in newGraph verticies

	//create array of adjacency lists. Size of array will be verticies
	newGraph->array = (adjacencyList*)malloc(verticies * sizeof(adjacencyList));

	//Initialize each adjacency list as empty by making head as NULL
	for (int i = 0; i < verticies; ++i)
		newGraph->array[i].head = NULL;
	
	return newGraph;
}

//adds edge to an undirected graph
void AdjacencyList::addEdge(struct adjacencyListGraph* newGraph, int src, int destination)
{
	//add an edge from source to destination. A new node is added to the adjacnecy list of src.
	//The node is added to the beginning
	struct adjacencyListNode* newNode = createAdjacencyListNode(destination);
	newNode->next = newGraph->array[destination].head;
	newGraph->array[src].head = newNode;

	//since it is undriected graph, add edge from destintion to src
	newNode = createAdjacencyListNode(src);
	newNode->next = newGraph->array[destination].head;
	newGraph->array[destination].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void AdjacencyList::printGraph(struct adjacencyListGraph* newGraph)
{
	//for loop which uses verticies as counter
	for (int v = 0; v < newGraph->verticies; ++v)
	{
		struct adjacencyListNode* print = newGraph->array[v].head;
		//printf("\n Adjacency list of vertex %d\n head ", v);
		std::cout << "Adjacency List of Vertex " << v;
		//loop which prints out all the edges
		while (print)
		{
			std::cout << print->destination;
			print = print->next;
		}
		std::cout << std::endl;
	}
}