// 1D Arrays in C
#include <stdio.h>

int main() { 
    int n, tmp, sum = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        sum += tmp;
    }
    
    printf("%d", sum);
    return 0;
}