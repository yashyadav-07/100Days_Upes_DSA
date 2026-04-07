/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V;

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i))
            return true;
    }
    return false;
}

int main() {
    V = 4;
    
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;
    adj[2][3] = 1;

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}