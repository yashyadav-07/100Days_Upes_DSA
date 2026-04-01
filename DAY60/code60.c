/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

bool isMinHeap(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return false;
}

bool isHeap(struct Node* root) {
    int totalNodes = countNodes(root);
    return isComplete(root, 0, totalNodes) && isMinHeap(root);
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    if (isHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}