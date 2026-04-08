/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int vertex;
    struct node* next;
};

struct node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void addEdge(int u, int v) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = adj[u];
    adj[u] = temp;
}

void dfs(int v) {
    visited[v] = 1;

    struct node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    stack[++top] = v;
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort(n);

    return 0;
}