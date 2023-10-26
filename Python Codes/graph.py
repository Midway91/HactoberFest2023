import numpy as np

def graphUsingMatrix():

    n = int(input("enter the number of nodes: "))
    mat = np.zeros((n, n))

    e = int(input("enter the number of edges: "))

    for _ in range(e):
        edge = input("enter edge: ")
        src, dst = edge.split("-")
        src = int(src)
        dst = int(dst)
        mat[src][dst] = 1

    print(mat)

class Graph:

    def __init__(self) -> None:
        self.neighbours = {}

    def addEdge(self, src, dst, direction):
        
        if src in self.neighbours:
            self.neighbours[src].append(dst)
        else:
            self.neighbours[src] = [dst]

        if not direction:
            if dst in self.neighbours:
                self.neighbours[dst].append(src)
            else:
                self.neighbours[dst] = [src]

    def printGraph(self):

        for node in self.neighbours:
            print(node, " ==> ", self.neighbours[node])

    def bfs(self, src):

        nodes = [src]
        visited = {}
        visited[src] = 1

        while nodes:
            
            front = nodes.pop(0)
            print(front, end=", ")

            for neighbour in self.neighbours.get(front, []):
                if neighbour not in visited:
                    nodes.append(neighbour)
                    visited[neighbour] = 1
    
    def dfs(self, src, visited):
        
        print(src, end=", ")
        visited[src] = 1

        for neighbour in self.neighbours.get(src, []):
            if neighbour not in visited:
                self.dfs(neighbour, visited)

    def checkCycleUsingBFS(self, src, visited):
        
        nodes = [src]
        visited[src] = 1

        parent = {}
        parent[src] = -1

        while nodes:

            front = nodes.pop(0)

            for nbr in self.neighbours.get(front, []):
                if nbr not in visited:
                    nodes.append(nbr)
                    visited[nbr] = 1
                    parent[nbr] = front
                else:
                    # already visited and front is not parent
                    if parent[front] != nbr:
                        return 1

        return 0
    
    def checkCycleUsingDFS(self, src, visited, parent):

        for neighbour in self.neighbours.get(src, []):
            if neighbour not in visited:
                visited[neighbour] = 1
                parent[neighbour] = src
                return self.checkCycleUsingDFS(neighbour, visited, parent)

            else:
                if parent[src] != neighbour and parent[src] != -1:
                    return 1

        return 0
    
    def topologicalSortDFS(self, src, queue, visited):

        visited[src] = 1

        for nbr in self.neighbours.get(src, []):
            if nbr not in visited:
                self.topologicalSortDFS(nbr, queue, visited)
        
        queue.append(src)
    
    def topologicalSortBFS(self, src, visited):

        nodes = [src]
        queue = []
        visited[src] = 1

        while nodes:

            front = nodes.pop(0)
            queue.append(front)

            for nbr in self.neighbours.get(front, []):
                if nbr not in visited:
                    nodes.append(nbr)
                    visited[nbr] = 1

        return queue


g = Graph()

g.addEdge(2,4,1);
g.addEdge(2,5,1);
g.addEdge(5,3,1);
g.addEdge(4,6,1);
g.addEdge(3,7,1);
g.addEdge(6,7,1);
g.addEdge(7,1,1);
g.addEdge(7,0,1);

print("Printing Graph..........")
g.printGraph()

print("\nPrinting Graph using BFS..........")
g.bfs(2)

print("\n\nPrinting Graph using DFS..........")
g.dfs(2, {})

print("\n\nChecking Cycle in Graph..........")
ans = 0
visited = {}
parent = {}

for i in range(6):
    if i not in visited:
        parent[i] = -1
        visited[i] = 1
        if g.checkCycleUsingDFS(i, visited, parent):
            ans = 1
            break

if ans:
    print("cycle is present\n")
else:
    print("cycle is not present\n")


print("Topological Sort Graph using DFS..........")
queue = []
visited = {}
g.topologicalSortDFS(2, queue, visited)
print(queue[::-1])

print("\nTopological Sort Graph using DFS..........")
visited = {}
queue = g.topologicalSortBFS(2, visited)
print(queue)

