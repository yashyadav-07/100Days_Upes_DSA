/*
Sample Test Cases:

Input 1:
hello

Output 1:
olleh

Input 2:
coding

Output 2:
gnidoc

Input 3:
a

Output 3:
a
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int i, len;

    scanf("%s", str);

    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}