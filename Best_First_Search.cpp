#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
   int x, y;
   int cost;
};

double euclideanDistance(int x1, int y1, int x2, int y2) {
   return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

struct NodeCompare {
   bool operator()(const Node& node1, const Node& node2) const {
      return node1.cost > node2.cost;
   }
};

void greedyBestFirstSearch(vector<vector<int>>& graph, Node start, Node goal) {
   int rows = graph.size();
   int cols = graph[0].size();

   priority_queue<Node, vector<Node>, NodeCompare> pq;
   unordered_set<int> visited;
   pq.push(start);

   while (!pq.empty()) {
      Node current = pq.top();
      pq.pop();

      if (current.x == goal.x && current.y == goal.y) {
         cout << "Goal node reached!" << endl;
         return;
      }

      int nodeId = current.x * cols + current.y;
      visited.insert(nodeId);

      int dx[] = {-1, 1, 0, 0};
      int dy[] = {0, 0, -1, 1};

      for (int i = 0; i < 4; i++) {
         int newX = current.x + dx[i];
         int newY = current.y + dy[i];

         if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
            double heuristicValue = euclideanDistance(newX, newY, goal.x, goal.y);

            if (visited.find(newX * cols + newY) == visited.end()) {
               Node neighbor;
               neighbor.x = newX;
               neighbor.y = newY;
               neighbor.cost = current.cost + graph[newX][newY];
               pq.push(neighbor);
            }
         }
      }
   }

   cout << "Goal node not reachable!" << endl;
}

int main() {
   vector<vector<int>> graph = {
      {3, 5, 1, 2},
      {1, 3, 2, 4},
      {5, 2, 6, 7},
      {4, 3, 1, 2}
   };

   Node start;
   start.x = 0;
   start.y = 0;
   start.cost = 0;

   Node goal;
   goal.x = 3;
   goal.y = 3;

   greedyBestFirstSearch(graph, start, goal);

   return 0;
}
