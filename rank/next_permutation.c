#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int     next_permutation(int n, char **s)
{
        int     i, j, L, R;
        char    *temp;

        if (n < 2)  return 1;

        L = -1;
        i = 0;
        while (i < n - 1)
        {
            if (strcmp(s[i], s[i + 1]) < 0) L = i;
            i++;
        }
        if (L < 0)  return 0;   
        
        i = L + 1;
        R = -1;
        while (i < n)
        {
            if (strcmp(s[L], s[i]) < 0) R = i;
            i++;
        }
        if (R < 0)  return 0;
        
        temp = s[L];
        s[L] = s[R];
        s[R] = temp;
        
        // Reverse the sequence from a[k + 1] up to and 
        // including the final element a[n] - wiki
        
        i = L + 1;
        j = n - 1;
        while (i < j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return 1;
}

//  DRIVE

int     main()
{
	char **s;
	int n;
	
        scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	
        for (int i = 0; i < n; i++)
	{
            s[i] = calloc(11, sizeof(char));
	    scanf("%s", s[i]);
	}
	
        do
        {
	    for (int i = 0; i < n; i++)
                printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	}   while (next_permutation(n, s));
	
        for (int i = 0; i < n; i++) free(s[i]);
	free(s);
	
        return 0;
}
