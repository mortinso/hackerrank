// Digit Frequency
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];
    scanf("%s", s);
    int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {   
            digits[s[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {   
        printf("%d ", digits[i]);
    }

    return 0;
}