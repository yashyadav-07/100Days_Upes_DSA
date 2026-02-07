/*
Sample Test Cases:

Input 1:
5
1 2 3 4 5

Output 1:
5 4 3 2 1

Input 2:
4
10 20 30 40

Output 2:
40 30 20 10

Input 3:
1
99

Output 3:
99
*/
#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);
    int a[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    int b[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}