// Sorting Array of Strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int get_distinct_chars(const char*s) {
    int distinct = 0;

    while (*s != '\0') {
        if (!strrchr(s + 1, *s)) {
            distinct++;
        }
        s++;
    }

    return distinct;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    if (get_distinct_chars(a) == get_distinct_chars(b))
        return lexicographic_sort(a, b);
    return get_distinct_chars(a) - get_distinct_chars(b);
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b))
        return lexicographic_sort(a, b);
    return strlen(a) - strlen(b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int sorted = -1;
    
    while (sorted < 0) {
        sorted = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (cmp_func(arr[i], arr[i + 1]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted--;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}