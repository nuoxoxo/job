#include <stdlib.h>
#include <stdio.h>

int     main()
{
    char    c;
    int     i;
    int     *ref;
    
    ref = malloc(sizeof(int) * 10);
    
    i = 0;
    while (i < 10)  ref[i++] = 0;
    while (scanf("%c", &c) == 1)
    {
        i = 0;
        while (i < 10)
        {
            if (i + 48 == c)    ref[i]++;
            i++;
        }
    }
    
    i = 0;
    while (i < 10)  printf("%i ", ref[i++]);
    printf("\n");
}
