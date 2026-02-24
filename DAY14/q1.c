/*
Sample Test Cases:

Input 1:
3 3
1 2 3
4 5 6
7 8 9

Output 1:
1 2 3 6 9 8 7 4 5


Input 2:
2 3
1 2 3
4 5 6

Output 2:
1 2 3 6 5 4


Input 3:
3 1
7
8
9

Output 3:
7 8 9


Input 4:
1 4
10 20 30 40

Output 4:
10 20 30 40


Input 5:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output 5:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    int matrix[n][n];
    int isIdentity = 1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                }
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
    }

    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}