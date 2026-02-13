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

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        for(int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}