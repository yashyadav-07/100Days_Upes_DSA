/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int vertex;
    int dist;
} Node;

Node pq[MAX];
int size = 0;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node n) {
    pq[size] = n;
    int i = size;
    size++;

    while (i > 0 && pq[(i - 1) / 2].dist > pq[i].dist) {
        swap(&pq[i], &pq[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop() {
    Node root = pq[0];
    pq[0] = pq[size - 1];
    size--;

    int i = 0;
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if (right < size && pq[right].dist < pq[left].dist)
            smallest = right;

        if (pq[i].dist <= pq[smallest].dist)
            break;

        swap(&pq[i], &pq[smallest]);
        i = smallest;
    }

    return root;
}

int isEmpty() {
    return size == 0;
}

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u];
    adj[u] = e;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    Node start = {src, 0};
    push(start);

    while (!isEmpty()) {
        Node curr = pop();
        int u = curr.vertex;

        Edge* temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                Node next = {v, dist[v]};
                push(next);
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    int n = 5;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 2, 5);
    addEdge(1, 3, 1);
    addEdge(2, 1, 3);
    addEdge(2, 3, 8);
    addEdge(2, 4, 2);
    addEdge(4, 3, 4);

    dijkstra(n, 0);

    return 0;
}