/*
Sample Test Cases:

Input 1:
3 3
1 2 3
4 5 6
7 8 9

Output 1:
15


Input 2:
2 3
1 2 3
4 5 6

Output 2:
6


Input 3:
3 1
7
8
9

Output 3:
7


Input 4:
1 4
10 20 30 40

Output 4:
10


Input 5:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output 5:
34
*/
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}