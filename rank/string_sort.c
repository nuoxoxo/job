#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  DRIVE

int     lexicographic_sort(const char* a, const char* b);
int     lexicographic_sort_reverse(const char* a, const char* b);
int     sort_by_number_of_distinct_characters(const char* a, const char* b);
int     sort_by_length(const char* a, const char* b);
int     sum_uniq_char(const char *s);
void    string_sort(char** arr, const int len, \
        int (*cmp_func)(const char* a, const char* b));
void    put_str_grid(char **s);

int     main(int argc, char **argv)
{
        
        const int       len = argc - 1;
        char            **head;
        head = argv;
        head++;
        string_sort(head, len, lexicographic_sort);
        string_sort(head, len, lexicographic_sort_reverse);
        string_sort(head, len, sort_by_number_of_distinct_characters);
        string_sort(head, len, sort_by_length);
}

//

void    string_sort(char** arr, const int len, \
        int (*cmp_func)(const char* a, const char* b))
{
        char    *temp;
        int     i;

        if (len < 2)    return ;
        i = 0;
        while (i < len - 1)
        {
                if (cmp_func(arr[i], arr[i + 1]) > 0)
                {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    i = 0;
                }
                else
                    i++;
        }
        put_str_grid(arr);
}

int     lexicographic_sort(const char* a, const char* b)
{
        int     i;

        i = 0;
        while (a[i] && b[i] && a[i] == b[i])    i++;
        return (a[i] - b[i]);
}

int     lexicographic_sort_reverse(const char* a, const char* b)
{
        int     i;

        i = 0;
        while (a[i] && b[i] && a[i] == b[i])    i++;
        return (b[i] - a[i]);
}

int     sort_by_number_of_distinct_characters(const char* a, const char* b)
{
        int     lena, lenb;

        lena = sum_uniq_char(a);
        lenb = sum_uniq_char(b);
        if (lena - lenb)    return (lena - lenb);
        return (lexicographic_sort(a, b));
}

int     sort_by_length(const char* a, const char* b)
{
        int     i, j;
        
        i = j = 0;
        while (a[i])    i++;
        while (b[j])    j++;
        if (i - j)      return (i - j);
        return (lexicographic_sort(a, b));
}

int     sum_uniq_char(const char *s)
{
        int     i, j, len, flag;

        if (!s) return (0);
        len = i = 1;
        while (s[i])
        {
                j = i - 1;
                flag = 0;
                while (s[j])
                {
                        if (s[i] == s[j])   flag++;
                        j--;
                }
                if (!flag)   len++;
                i++;
        }
        return (len);
}

void    put_str_grid(char **s)
{
        int     i = 0;
        while (s[i])    printf("%s\n", s[i++]);
        printf("\n");
}
