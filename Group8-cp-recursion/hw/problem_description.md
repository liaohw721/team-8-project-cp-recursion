## DFS Traversal of a Graph ##

# Problem Description 說明

Write a program to perform a Depth-First Search (DFS) traversal on a graph starting from node 0.
The graph is represented as an adjacency matrix. When visiting a node, print its number followed by a space.
Visit all reachable nodes using DFS recursion.

# Input Format

- The first line contains an integer n, the number of nodes in the graph (numbered from 0 to n-1).

- The next n lines each contain n integers (0 or 1), representing the adjacency matrix of the graph.

    * 1 indicates an edge between nodes, and 0 indicates no edge.

# Output Format

Print the nodes in the order they are visited by DFS, separated by spaces, in a single line.

# Sample Input 1
4
0 1 1 0
1 0 0 1
1 0 0 0
0 1 0 0

# Sample Output 1
0 1 3 2

# Hint

- Use a recursive function to visit each node.

- Keep track of visited nodes using an array.

- Start DFS traversal from node 0.

- For each node, recursively visit all unvisited neighbors in increasing order of their indices.

# Constraints

1. 1 <= n <= 100

2. Each element of the adjacency matrix is either 0 or 1.

3. The graph may be disconnected; only visit nodes reachable from node 0.