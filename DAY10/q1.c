/*
Sample Test Cases:

Input 1:
level

Output 1:
YES

Input 2:
madam

Output 2:
YES

Input 3:
hello

Output 3:
NO

Input 4:
a

Output 4:
YES

Input 5:
abba

Output 5:
YES
*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int left, right, flag = 1;

    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}