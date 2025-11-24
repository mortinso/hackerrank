// Small Triangles, Large Triangles
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double area(triangle tr) {
    double a = tr.a, b = tr.b, c = tr.c;
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int is_sorted(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (area(tr[i]) > area(tr[i + 1])) {   
            return 0;
        }
    }
    return 1;
}

void sort_by_area(triangle* tr, int n) {
	while (!is_sorted(tr, n)) {
        for (int i = 0; i < n - 1; i++) {
            if (area(tr[i]) > area(tr[i + 1])) {
                triangle tmp = tr[i];
                tr[i] = tr[i + 1];
                tr[i + 1] = tmp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}