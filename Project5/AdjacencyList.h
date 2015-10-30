class AdjacencyList
{
private:
	//A struct to represent an adjacency list node
	struct adjacencyListNode
	{
		int destination;
		struct adjacencyListNode* next;//store address of next verticie
		struct adjacencyListNode* previous;//points to previous node/verticie
	};
	//A struct to represent an adjacency list
	struct adjacencyList
	{
		struct adjacencyListNode* head;//where first word goes in
	};

	//A struct to represent a graph. A graph is an array of adjacency lists
	//size of array will be V (number of verticies in graph
	struct adjacencyListGraph
	{
		int verticies;//number of verticies on graph
		struct adjacencyList* array;
	};

	//A utility function to create a new adjacency list node
	struct adjacencyListNode* createAdjacencyListNode(int dest);

	//A utility function that creates a graph of V vertities
	struct adjacencyListGraph* createGraph(int verticies);

	//adds an edge to an undirected graph
	void addEdge(struct adjacencyListGraph* graph, int src, int dest);

	//print adjacency List
	void printGraph(struct adjacencyListGraph* newGraph);

public:
	AdjacencyList();

};
