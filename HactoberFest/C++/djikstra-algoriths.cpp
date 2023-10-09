#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void dijkstra(int source);

private:
    int vertices;
    vector<vector<pair<int, int>>> adjacencyList; // Pair: (neighbor, edge weight)
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyList[u].push_back(make_pair(v, weight));
    adjacencyList[v].push_back(make_pair(u, weight)); // For undirected graph
}

void Graph::dijkstra(int source) {
    vector<int> distance(vertices, INF);
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjacencyList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    cout << "Shortest distances from source " << source << " to all other vertices:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int vertices = 6;
    Graph graph(vertices);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 2);

    int source = 0;
    graph.dijkstra(source);

    return 0;
}
