// For Loops in C
#include <stdio.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    
    char *arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = a; i <= b; i++) {
        if (i <= 9)
            printf("%s\n", arr[i - 1]);
        else if (i % 2 != 0)
            printf("odd\n");
        else
            printf("even\n");
    }

    return 0;
}