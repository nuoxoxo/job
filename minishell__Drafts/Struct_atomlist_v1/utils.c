#include "Atomlist.h"
#include "Envlist.h"

//	checkers

int	check_string_isempty(char *line) // check if nothing but whitesp in line
{
	while (*line)
	{
		if (!ft_strchr(WHITE_SPACE, *line))
			return (0);
		line++;
	}
	return (1);
}

int	check_quote_isvalid(char *line)
{
	int	single_quote;
	int	double_quote;

	single_quote = 196883;
	double_quote = 196883;
	while (*line)
	{
		if (ft_strncmp(line, "\\\\", 2) == 0 || \
			ft_strncmp(line, "\\'", 2) == 0 || \
			ft_strncmp(line, "\\\"", 2) == 0)
		{
			line += 2;
			continue ;
		}
		if (double_quote == 196883 && *line == '\'')
			single_quote = -single_quote;
		if (single_quote == 196883 && *line == '"')
			double_quote = -double_quote;
		line++;
	}
	if (single_quote + double_quote > 0)
		return 1;
	return 0;
}

int	check_pipeline(t_atom *atom)
{
	int	option;

	option = 1;
	if (atom->type == T_PIPE)
		option = 0;
	while (atom && option == 1)
	{
		if (atom->type == T_PIPE && !atom->next)
			option = 0;
		else if (atom->type > T_PIPE && \
			(!atom->next || atom->next->type >= T_PIPE))
			option = 0;
		atom = atom->next;
	}
	if (option == 1)
		return 1;
	return (0);
}

void	atomlist_print(t_atom *node)
{
	if (!node)
		printf("(null)\n");
	display_default_type_enum();
	while (node)
	{
		printf( color1 "(type: %d) " noc , node->type);
		printf( color2 "%s " noc , node->str);
		if (node->next)
			printf("\n");
		else
			printf("\n(end) \n");
		node = node->next;
	}
}

void	display_default_type_enum(void)
{
	printf("\n- \n");
	printf("1 : T_ENV \n");
	printf("2 : T_OFF \n");
	printf("3 : T_PIPE \n");
	printf("4 : T_REDIR_IN \n");
	printf("5 : T_HEREDOC \n");
	printf("6 : T_REDIR_OUT \n");
	printf("7 : T_APPEND \n");
	printf("- \n");
}
