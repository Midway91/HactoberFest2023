const V = 9;

function minDistance(dist, sptSet) {
  let min = Infinity;
  let minIndex;

  for (let v = 0; v < V; v++) {
    if (!sptSet[v] && dist[v] <= min) {
      min = dist[v];
      minIndex = v;
    }
  }

  return minIndex;
}

function printSolution(dist) {
  console.log("Vertex \t\t Distance from Source");
  for (let i = 0; i < V; i++) {
    console.log(i + " \t\t\t\t " + dist[i]);
  }
}

function dijkstra(graph, src) {
  const dist = new Array(V);
  const sptSet = new Array(V).fill(false);

  for (let i = 0; i < V; i++) {
    dist[i] = Infinity;
    sptSet[i] = false;
  }

  dist[src] = 0;

  for (let count = 0; count < V - 1; count++) {
    const u = minDistance(dist, sptSet);
    sptSet[u] = true;

    for (let v = 0; v < V; v++) {
      if (!sptSet[v] && graph[u][v] && dist[u] != Infinity && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printSolution(dist);
}

const graph = [
  [0, 4, 0, 0, 0, 0, 0, 8, 0],
  [4, 0, 8, 0, 0, 0, 0, 11, 0],
  [0, 8, 0, 7, 0, 4, 0, 0, 2],
  [0, 0, 7, 0, 9, 14, 0, 0, 0],
  [0, 0, 0, 9, 0, 10, 0, 0, 0],
  [0, 0, 4, 14, 10, 0, 2, 0, 0],
  [0, 0, 0, 0, 0, 2, 0, 1, 6],
  [8, 11, 0, 0, 0, 0, 1, 0, 7],
  [0, 0, 2, 0, 0, 0, 6, 7, 0]
];

dijkstra(graph, 0);
