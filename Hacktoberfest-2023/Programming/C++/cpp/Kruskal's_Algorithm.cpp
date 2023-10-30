#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint-set (for cycle detection)
struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unionSets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v)
            parent[u] = v;
    }
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

void kruskalMST(vector<Edge> &edges, int numVertices) {
    // Sort the edges in ascending order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize a disjoint-set data structure
    DisjointSet ds(numVertices);

    vector<Edge> minimumSpanningTree;
    int mstWeight = 0;

    for (const Edge &edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        // Check if adding this edge creates a cycle in the MST
        if (ds.find(u) != ds.find(v)) {
            minimumSpanningTree.push_back(edge);
            mstWeight += edge.weight;
            ds.unionSets(u, v);
        }
    }

    // Output the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge &edge : minimumSpanningTree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    cout << "Total Weight: " << mstWeight << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<Edge> edges;
    cout << "Enter the source, destination, and weight for each edge:" << endl;
    for (int i = 0; i < numEdges; i++) {
        Edge edge;
        cin >> edge.src >> edge.dest >> edge.weight;
        edges.push_back(edge);
    }

    kruskalMST(edges, numVertices);

    return 0;
}
