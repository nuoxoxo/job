#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *stringToBinary(char *_);
char    *ft_strcat(char *_, const char* __);

int     main()
{
        char    s[] = "hello";
        printf("%s\n", stringToBinary(s));
}

char* stringToBinary(char* s) {
    if(s == NULL) return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len*8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                ft_strcat(binary,"1");
            } else {
                ft_strcat(binary,"0");
            }
        }
    }
    return binary;
}

char	*ft_strcat(char *des, const char *src)
{
        int    i;
        int    j;

        i = 0;
        j = 0;
        while (des[i])
            i++;
        while (src[j])
        {
            des[i + j] = src[j];
            j++;
        }
        des[i + j] = 0;
        return (des);
}

