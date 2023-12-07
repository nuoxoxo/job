//      how it works :
//      	copy at most SIZE - 1 bytes (size-bounded concat)
//      	pushes NUL at SIZE-th byte
//      return :
//      	len of src (ie. length of the string it wants to create)

#include <unistd.h>

size_t	len(char *s);

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = len((char *)src);
	i = 0;
	while (src[i] && i < size - 1)
	{
		des[i] = src[i];
		i++;
	}
	des[i] = 0;
	return (len_src);
}

size_t	len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*

//  DRIVE

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define	OUT	printf("\n(ctrl + c to quit)\n--\n\n")
#define	ENDL	printf("\n\n")
#define	LOAD	loading()

void    loading(void);

int     main(void)
{
	while (1)
        {
		const int	max = 64;
		char		des_std[max], des_usr[max], src[max];
		size_t		res_std, res_usr, size, len_src, len_des;

		fflush(stdin);
		printf("src : ");
		fgets(src, max, stdin);
		src[ len(src) - 1 ] = 0;
		len_src = len(src);
		fflush(stdin);
		printf("des : ");
		fgets(des_std, max, stdin);
		des_std[ len(des_std) - 1 ] = 0;
		len_des = len(des_std);
		fflush(stdin);
		printf("size : ");
		scanf("%zi", &size);
		LOAD;
		printf("len(src) = %zi\n", len_src);
		printf("len(des) = %zi\n\n", len_des);
		strcpy(des_usr, des_std);
		printf("-- compare return value --\n");
		res_std = strlcpy(des_std, src, size);
		res_usr = ft_strlcpy(des_usr, src, size);
		printf("stdlib  : %zi\n", res_std);
		printf("my lib  : %zi\n\n", res_usr);
		printf("-- compare result --\n");
		printf("comp : %s\n", des_std);
		printf("user : %s\n", des_usr);
		OUT;
	}
        return (0);
}

//

void    loading(void)
{
        int     rand;

        rand = 1000 * 32;
        printf("loading");
        for (int i = 12; i > 0; i--)
        {
            usleep(rand);
            printf(".");
        }
        ENDL;
}

*/
