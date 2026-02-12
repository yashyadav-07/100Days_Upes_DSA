/*
Sample Test Cases:

Input 1:
2 2
1 2
2 1

Output 1:
Symmetric Matrix


Input 2:
3 3
1 2 3
2 4 5
3 5 6

Output 2:
Symmetric Matrix


Input 3:
3 3
1 0 1
2 3 4
1 4 5

Output 3:
Not a Symmetric Matrix


Input 4:
2 3
1 2 3
4 5 6

Output 4:
Not a Symmetric Matrix
*/
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}