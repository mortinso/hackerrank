// Playing With Characters
#include <stdio.h>

int main() 
{
    char c;
    char s[101];
    char line[101];
    
    scanf("%c", &c);
    printf("%c\n", c);
    
    scanf("%s%*c", s);
    printf("%s\n", s);
    
    scanf("%[^\n]%*c", line);
    printf("%s\n", line);
    return 0;
}