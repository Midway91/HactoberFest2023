#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 9


int minDistance(int dist[], bool path[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (path[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}


// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool path[V]; // path[i] will be true if vertex i is
					// included in shortest
	

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, path[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, path);

		// Mark the picked vertex as processed
		path[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in path,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!path[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}


int main()
{

	int v;
	cin>>v;
	int  graph[v][v];
    for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			cin>>graph[i][j];
		}
	}
	

	// Function call
	dijkstra(graph, 0);

	return 0;
}
