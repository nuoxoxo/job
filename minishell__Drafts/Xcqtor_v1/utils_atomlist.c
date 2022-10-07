#include "v6.h"

void	charset_parse(char **line, char *charset, t_atom **atomlist)
{
	t_atom		*atom;

	while (ft_strchr(charset, **line) && **line != '\0')
	{
		atom = null;
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

	// print_atomlist(*atom); // debugger

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
	if (len == (int) ft_strlen(s))
		return (null);
	i = 0;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		ft_exit_error_alloc();
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
			quote_wrap(& s, & double_quote, & single_quote, & len);
		else
			len++;
		if (*s)
			s++;
	}
	return (len);
}

void	quote_wrap(char **s, int *quote1, int *quote2, int *len)
{
	if (**s == '\\')
	{
		print(color2 " inside wrap: %s \n" noc, *s); // debugger
		if (*quote1 == 1 && *quote2 == 1 && *(*s + 1) != '\0')
			(**s) = '\0';
		else if (*quote1 == -1 || *quote2 == -1)
			(*len)++;
		(*len)++;
		(*s)++;
		print(color2 " inside wrap: %s \n\n" noc, *s); // debugger
		return ;
	}
	if (*quote1 == -1 || (*quote1 == 1 && *quote2 == 1))
	{
		print(color3 " inside wrap: %s \n" noc, *s); // debugger
		(*quote1) = -(*quote1);
		(**s) = '\0';
		print(color3 " inside wrap: %s \n\n" noc, *s); // debugger
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
	{
		return ;
	}
	else
	{
		(*i)++;
	}
}
