/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adjLists[MAX_NODES];
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int s, int d) {
    struct Node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}

void bfs(struct Graph* graph, int n, int startNode) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[startNode] = true;
    queue[rear++] = startNode;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        struct Node* temp = graph->adjLists[currentNode];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, edges, s, u, v;
    struct Graph* graph = malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_NODES; i++) graph->adjLists[i] = NULL;

    scanf("%d %d", &n, &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    scanf("%d", &s);

    bfs(graph, n, s);

    return 0;
}