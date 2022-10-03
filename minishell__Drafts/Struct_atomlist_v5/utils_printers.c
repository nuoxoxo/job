#include "v5.h"

//	printer-debuggers

void	print_char_star_array(char **arr)
{
	int		i;

	if (!(*arr))
		return ;
	i = 0;
	while (arr[i])
		print(color3 " %s \n" noc, arr[i++]);
	nl;
}

void	print_invalid_quote(int sq, int dq)
{
	print(color1 "\nquotes not valid\n('): %d\n(\"): %d\n\n" noc, sq, dq);
}

void	print_input(char *line)
{
	print(nl " Input : " color1 "%s " noc, line);
	print(nl " Length: " color2 "%d " noc, (int)ft_strlen(line));
	print(nl2);
}

void	print_default_type_enum(void)
{
	printf("\n- \n");
	printf("1 : T_ENV \n");
	printf("2 : T_OFF \n");
	printf("3 : T_PIPE \n");
	printf("4 : T_REDIR_IN \n");
	printf("5 : T_REDIR_OUT \n");
	printf("6 : T_APPEND \n");
	printf("7 : T_HEREDOC \n");
	printf("- \n");
}
