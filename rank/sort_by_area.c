#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct  triangle
{
        int a;
        int b;
        int c;
}               triangle;

double  area_tr(triangle t);
void    sort_by_area(triangle *triangle, int n);
void    swap_tr(triangle *t1, triangle *t2);

// DRIVE

int     main()
{
	int n;
	
        scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d - area : %f\n", \
                tr[i].a, tr[i].b, tr[i].c, area_tr(tr[i]));
	}
	return 0;
}

//

void    sort_by_area(triangle *tr, int n)
{
        int     i;

        if (n < 2)  return ;
        i = 0;
        while (i < n - 1)
        {
                if (area_tr(tr[i]) > area_tr(tr[i + 1]))
                {
                        swap_tr(&tr[i], &tr[i + 1]);
                        i = 0;
                }
                else    i++;
        }
}

void    swap_tr(triangle *t1, triangle *t2)
{
        triangle    temp;
        temp = *t1;
        *t1 = *t2;
        *t2 = temp;
}

double  area_tr(triangle t)
{
        double  p;

        p = (double)(t.a + t.b + t.c) / 2;
        return sqrt(p * (p - (double)t.a) * \
        (p - (double)t.b) * (p - (double)t.c));
}
