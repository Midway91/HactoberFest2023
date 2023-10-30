import heapq

# Define the grid and its dimensions
grid = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0]
]
rows, cols = len(grid), len(grid[0])

# Define the movement directions (up, down, left, right, and diagonals)
directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

# A* algorithm
def a_star(start, goal):
    open_set = []  # Priority queue for open nodes
    closed_set = set()  # Set of closed nodes
    came_from = {}  # Parent node for each node
    g_score = {cell: float('inf') for row in grid for cell in row}  # Cost from start to current node
    g_score[start] = 0
    f_score = {cell: float('inf') for row in grid for cell in row}  # Estimated total cost from start to goal
    f_score[start] = heuristic(start, goal)

    heapq.heappush(open_set, (f_score[start], start))

    while open_set:
        _, current = heapq.heappop(open_set)

        if current == goal:
            return reconstruct_path(came_from, current)

        closed_set.add(current)

        for dr, dc in directions:
            neighbor = (current[0] + dr, current[1] + dc)

            if not (0 <= neighbor[0] < rows) or not (0 <= neighbor[1] < cols):
                continue

            if grid[neighbor[0]][neighbor[1]] == 1:
                continue

            tentative_g_score = g_score[current] + 1

            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)

                if neighbor not in closed_set:
                    heapq.heappush(open_set, (f_score[neighbor], neighbor))

    return None  # No path found

# Heuristic function (Euclidean distance)
def heuristic(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

# Reconstruct the path from start to goal
def reconstruct_path(came_from, current):
    path = []

    while current in came_from:
        path.append(current)
        current = came_from[current]

    path.append(current)
    path.reverse()
    return path

# Define the start and goal positions
start = (0, 0)
goal = (4, 4)

# Find the path using A*
path = a_star(start, goal)

# Print the grid with the path
for row in range(rows):
    for col in range(cols):
        if (row, col) in path:
            print("P", end=" ")  # Path
        elif grid[row][col] == 1:
            print("X", end=" ")  # Obstacle
        else:
            print(".", end=" ")  # Open space
    print()
