/*
/*
Task Description
Write a program to perform a Depth-First Search (DFS) traversal on a graph
starting from node 0. The graph is represented by an adjacency matrix. When
visiting a node, print its number followed by a space. Visit all reachable nodes
using DFS recursion.

Input Format
The first line contains an integer n, the number of nodes in the graph (numbered
from 0 to n-1). The next n lines each contain n integers (0 or 1), representing
the adjacency matrix of the graph. A 1 indicates an edge between nodes, and 0
indicates no edge.

Output Format
Print the nodes in the order they are visited by DFS, separated by spaces, in a
single line.
*/

/*How this recursion works:

dfs(node) visits a node, then recursively calls dfs() on all its neighbors that
haven’t been visited yet.

The base case is implicit: if a node has no unvisited neighbors, recursion
stops.

The call stack naturally backtracks to previous nodes.
*/

#include <stdio.h>

int visited[100];
int graph[100][100];
int n;

void dfs(int node) {
  visited[node] = 1;
  printf("%d ", node);
  for (int i = 0; i < n; i++) {
    if (graph[node][i] && !visited[i]) {
      dfs(i); // 🔁 recursion here
    }
  }
}

int main() {
  scanf("%d", &n); // number of nodes
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]); // adjacency matrix

  dfs(0); // start from node 0
  return 0;
}
