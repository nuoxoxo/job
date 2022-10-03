#include "v5.h"

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

	single_quote = 1; // 1 is closed, -1 open
	double_quote = 1;
	while (*line)
	{
		// handle:	\\ . \' . \"
		if (check_char_isescaped(line))
		{
			line += 2;
			continue ;
		}
		// if type_1 is Closed (1) and a type_2 appears, equation evals to < 0
		single_quote *= check_quote_single_vs_double(double_quote, *line);
		double_quote *= check_quote_double_vs_single(single_quote, *line);
		line++;
	}

	// ↘ valid when both > 0; invalid when either or both < 0
	if (single_quote + double_quote > 0)
		return 1;

	print_invalid_quote(single_quote, double_quote); // dbg
	return 0;
}

int	check_quote_double_vs_single(int sq, char c)
{
	if (sq == 1 && c == '\"')
		return -1;
	return 1;
}

int	check_quote_single_vs_double(int dq, char c)
{
	if (dq == 1 && c == '\'')
		return -1;
	return 1;
}

int	check_char_isescaped(char *ptr)
{
	if (ft_strncmp(ptr, "\\\\", 2) == 0 || \
		ft_strncmp(ptr, "\\'", 2) == 0 || \
		ft_strncmp(ptr, "\\\"", 2) == 0)
		return 1;
	return 0;
}

int	check_pipeline(t_atom *atom)
{
	int	ok;

	ok = 1;
	if (atom->type == T_PIPE)
		ok = 0;
	while (atom && ok == 1)
	{
		if (atom->type == T_PIPE && !atom->next)
			ok = 0;
		else if (atom->type > T_PIPE && \
			(!atom->next || atom->next->type >= T_PIPE))
			ok = 0;
		atom = atom->next;
	}
	if (ok == 1)
		return 1;
	return (0);
}