/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdbool.h>

void dfs(int u, int n, int adj[n][n], bool visited[]) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v, n, adj, visited);
        }
    }
}

int main() {
    int n, s;
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    dfs(s, n, adj, visited);

    return 0;
}