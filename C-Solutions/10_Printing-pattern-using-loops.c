// Printing Pattern Using Loops
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int side = (n * 2) - 1;

    for (int y = 0; y < side; y++)
    {
        for (int x = 0; x < side; x++)
        {
            int y_dist = abs(y < n ? y - n: n - y - 2);
            int x_dist = abs(x < n ? x - n: n - x - 2); 
            printf("%d ", (y_dist > x_dist? y_dist: x_dist));
        }
        printf("\n");
    }
    return 0;
}