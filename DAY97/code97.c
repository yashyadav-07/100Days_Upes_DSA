/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

int peek(int heap[]) {
    return heap[0];
}

int minRooms(Meeting arr[], int n) {
    qsort(arr, n, sizeof(Meeting), compare);

    int heap[n];
    int size = 0;

    push(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= peek(heap)) {
            pop(heap, &size);
        }
        push(heap, &size, arr[i].end);
    }

    return size;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    printf("%d\n", minRooms(arr, n));

    return 0;
}