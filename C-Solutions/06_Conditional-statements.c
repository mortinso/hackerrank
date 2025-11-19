// Conditional Statements in C
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    const char *arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;

    if (scanf("%d", &n) < 1)
        return 1;

    if (n >= 1 && n <= 9)
        printf("%s\n", arr[n - 1]);
    else
        printf("Greater than 9\n");

    return 0;
}