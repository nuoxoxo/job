#include "Atomlist.h"
#include "Envlist.h"

//	printers

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

void	print_invalid_quote(int sq, int dq)
{
	print(color1 "\nquotes not valid\n('): %d\n(\"): %d\n\n" noc, sq, dq);
}
