/*
Sample Test Cases:

Input 1:
2 2
1 2
3 4
5 6
7 8

Output 1:
6 8
10 12


Input 2:
1 3
10 20 30
1 2 3

Output 2:
11 22 33


Input 3:
3 1
1
2
3
4
5
6

Output 3:
5
7
9
*/
#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n], b[m][n], sum[m][n];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            sum[i][j] = a[i][j] + b[i][j];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}