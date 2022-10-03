#include "Atomlist.h"
#include "Envlist.h"
#include "stdio.h"

void	charset_parse(char **line, char *charset, t_atom **atomlist)
{
	t_atom		*atom;

	while (ft_strchr(charset, **line) && **line != '\0')
	{
		atom = NULL;
		if (!ft_strncmp(*line, "<<", 2) || !ft_strncmp(*line, ">>", 2))
			charset_assign(& atom, line, 2);
		else if (ft_strchr("|<>", **line))
			charset_assign(& atom, line, 1);
		if (atom)
			atomlist_append(atomlist, atom);
		(*line)++;
	}
}

void	charset_assign(t_atom **atom, char **line, int option)
{
	if (option ^ 1 && option ^ 2)
		return ;
	(*atom) = atomlist_new_node(
		ft_strndup_protected(*line, option)
	);

	// atomlist_print(*atom); // debugger

	if (option == 2)
	{
		if (**line == '<')
			(*atom)->type = T_HEREDOC;
		else if (**line == '>')
			(*atom)->type = T_APPEND;
		(*line)++;
		return ;
	}
	// option is 1
	if (**line == '<')
		(*atom)->type = T_REDIR_IN;
	else if (**line == '>')
		(*atom)->type = T_REDIR_OUT;
	else if (**line == '|')
		(*atom)->type = T_PIPE;
}

char	*quote_trim(char *s)
{
	char		*res;
	int		len;
	int		i;

	len = quote_trim_len(s);
	print(color2 "¡¡¡ Trim Len = %d \n" noc, len);
	if (len == (int) slen(s))
		return (NULL);
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		exit_error_alloc();
	i = 0;
	while (i < len)
	{
		if (*s != '\0')
		{
			res[i++] = *s;
		}
		s++;
	}
	res[i] = '\0';
	return (res);
}

int	quote_trim_len(char *s)
{
	int	len;
	int	double_quote;
	int	single_quote;

	len = 0;
	double_quote = 1;
	single_quote = 1;
	// print(color1 "¡¡¡ Before While: Str = %s \n" noc, s);
	while (*s)
	{
		if (*s == '"')
			quote_wrap(& s, & double_quote, & single_quote, & len);
		else if (*s == '\'')
			quote_wrap(& s, & single_quote, & double_quote, & len);
		else if (ft_strncmp(s, "\\\\", 2) == 0)
		{
			*(++s) = '\0';
			len++;
		}
		else if (*s == '\\')
		{
			// print(color2 "¡¡¡ Before Wrap: len = %d \n" noc, len);
			quote_wrap(& s, & double_quote, & single_quote, & len);
			// print(color2 "¡¡¡ After Wrap: len = %d \n" noc, len);
		}
		else
			len++;
		// print(color3 "¡¡¡ Before s++: Str = %s, Len = %d \n" noc, s, len);
		if (*s)
			s++;
		// print(color3 "¡¡¡ After s++: Str = %s, Len = %d \n" noc, s, len);
	}
	// print(color1 "¡¡¡ After While: Str = %s, Len = %d \n" noc, s, len);
	return (len);
}

void	quote_wrap(char **s, int *q1, int *q2, int *len)
{
	if (**s == '\\')
	{
		print(color2 " inside wrap: %s \n" noc, *s); // debugger

		if (*q1 == 1 && *q2 == 1 && *(*s + 1) != '\0')
			(**s) = '\0';
		else if (*q1 == -1 || *q2 == -1)
			(*len)++;
		(*len)++;
		(*s)++;

		print(color3 " inside wrap: %s \n\n" noc, *s); // debugger
		return ;
	}
	if (*q1 == -1 || (*q1 == 1 && *q2 == 1))
	{
//		print(color3 " inside wrap: %s \n" noc, *s); // debugger

		(*q1) = -(*q1);
		(**s) = '\0';

//		print(color3 " inside wrap: %s \n\n" noc, *s); // debugger
	}
	else
	{
		(*len)++;
	}
}

void	quote_skip(char *s, int *i, int *single_quote)
{
	if ((*i) == 0 && s[(*i)] == '\'')
		(*single_quote) *= -1;
	else if (ft_strchr("\\$\"", s[(*i)]) == 0 \
			&& s[(*i) + 1] == '\'')
	{
		(*i)++;
		(*single_quote) *= -1;
	}
	else if ((*single_quote) == 1 && s[(*i)] == '$')
		return ;
	else
		(*i)++;
}
