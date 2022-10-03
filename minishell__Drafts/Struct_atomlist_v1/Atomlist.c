#include "Atomlist.h"
#include "Envlist.h"

int	atomlist_get(char *line, t_atom **atom, t_env *envlist)
{
	if (check_string_isempty(line) || !check_quote_isvalid(line))
	{
		return 0;
	}
	(*atom) = atomlist_from_line(line, " |<>");
	atomlist_from_envlist(*atom, envlist);
	atomlist_trim(*atom);
	if (!(*atom) || !check_pipeline(*atom))
	{
		atomlist_free(*atom);
		return 0;
	}
	//atomlist_print(*atom);
	return 1;
}

void	atomlist_free(t_atom *node)
{
	t_atom		*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->str);
		temp->str = NULL;
		temp->next = NULL;
		free(temp);
		temp = NULL;
	}
}

t_atom	*atomlist_from_line(char *line, char *charset)
{
	t_atom		*atomlist;
	char		*temp;


	atomlist = NULL;
	while (*line != '\0')
	{
		charset_parse(& line, charset, & atomlist);

		temp = atom_create(& line);

		while (*line != '\0' && !ft_strchr(charset, *line))
			temp = ft_strjoin2(temp, atom_create(& line));


		if (temp)
			atomlist_append(& atomlist, atomlist_new_node(temp));
	}
	return (atomlist);
}

void	atomlist_from_envlist(t_atom *atom, t_env *envlist)
{
	char		*s;
	int		i;
	int		single_quote;

	while (atom)
	{
		i = -1;
		single_quote = 196883;
		s = sdup2(atom->str);
		while (++i < slen(s))
		{
			quote_skip(s, & i, & single_quote);
			if (single_quote == 196883 && s[i] == '$')
			{
				atom->type = T_ENV;
				atom->str = envlist_insert(envlist, atom->str, s + i);
			}
		}
		atom = atom->next;
		free(s);
	}
}

void	atomlist_trim(t_atom *atom)
{
	char	*line;
	char	*temp;

	while (atom)
	{
		temp = atom->str;
		line = quote_trim(atom->str);
		if (line)
		{
			atom->str = line;
			free(temp);
		}
		atom = atom->next;
		temp = NULL;
	}
}

void	charset_parse(char **line, char *charset, t_atom **atomlist)
{
	t_atom		*atom;

	while (ft_strchr(charset, **line) && **line != '\0')
	{
		atom = NULL;
		if (!ft_strncmp(*line, "<<", 2) || !ft_strncmp(*line, ">>", 2))
			charset_sort(& atom, line, 2);
		else if (ft_strchr("|<>", **line))
			charset_sort(& atom, line, 1);
		if (atom)
			atomlist_append(atomlist, atom);
		(*line)++;
	}
}

void	charset_sort(t_atom **atom, char **line, int option)
{
	(*atom) = atomlist_new_node(sndup2(*line, option));
	if (option == 2)
	{
		if (**line == '<')
			(*atom)->type = T_HEREDOC;
		else if (**line == '>')
			(*atom)->type = T_APPEND;
		(*line)++;
	}
	else
	{
		if (option == 1 && **line == '<')
			(*atom)->type = T_REDIR_IN;
		else if (option == 1 && **line == '>')
			(*atom)->type = T_REDIR_OUT;
		else if (option == 1 && **line == '|')
			(*atom)->type = T_PIPE;
	}
}

char	*atom_create(char **line)
{
	int		len;
	char		*s;

	if (**line == '\0')
		return (NULL);
	len = 0;
	if (**line != '"' && **line != '\'')
		atom_len(*line, & len, 0); // count atom len . done
	else
		atom_len(*line, & len, 1);
	s = sndup2(*line, len);
	(*line) += len;
	return (s);
}

void	atom_len(char *line, int *len, int n_quote)
{
	if (n_quote == 1)
	{
		(*len)++;
		while (line[*len] != *line)
		{
			if (ft_strncmp(line + (*len), "\\\\", 2) == 0)
				(*len)++;
			else if (line[*len] == '\\'
				&& ft_strchr("'\"", line[*len + 1]))
				(*len)++;
			(*len)++;
		}
		(*len)++;
		return ;
	}
	while (line[*len] != '\0' && !ft_strchr(" <>|'\"", line[*len]))
	{
		if (ft_strncmp(line + *len, "\\\\", 2) == 0)
			(*len)++;
		else if (line[*len] == '\\'
			&& ft_strchr("'\"", line[*len + 1]))
			(*len)++;
		(*len)++;
	}
}

//	atomlist

t_atom	*atomlist_new_node(char *s)
{
	t_atom		*atom;

	atom = (t_atom *) malloc(sizeof(t_atom));
	if (!atom)
		exit_error_alloc();
	atom->prev = NULL;
	atom->next = NULL;
	atom->type = T_OFF;
	atom->str = s;

	return (atom);
}

void	atomlist_append(t_atom **atomlist, t_atom *atom)
{
	t_atom		*temp;

	if (*atomlist == NULL)
	{
		(*atomlist) = atom;
	}
	else
	{
		temp = *atomlist;
		while ((*atomlist)->next)
		{
			*atomlist = (*atomlist)->next;
		}
		(*atomlist)->next = atom;
		atom->prev = (*atomlist);
		atom->next = NULL;
		*atomlist = temp;
	}

}

char	*quote_trim(char *s)
{
	char		*res;
	int		len;
	int		i;

	len = quote_trim_len(s);
	if (len == (int) slen(s))
		return (NULL);
	i = 0;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		exit_error_alloc();
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
	double_quote = 196883;
	single_quote = 196883;
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
		s++;
	}
	return (len);
}

void	quote_wrap(char **s, int *quote1, int *quote2, int *len)
{
	if (**s == '\\')
	{
		if (*quote1 == 196883 && *quote2 == 196883 && *(*s + 1) != '\0')
			(**s) = '\0';
		else if (*quote1 == -196883 || *quote2 == -196883)
			(*len)++;
		(*len)++;
		(*s)++;
		return ;
	}
	if (*quote1 == -196883 || (*quote1 == 196883 && *quote2 == 196883))
	{
		(*quote1) = -(*quote1);
		(**s) = '\0';
	}
	else
		(*len)++;
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
	else if ((*single_quote) == 196883 && s[(*i)] == '$')
		return ;
	else
		(*i)++;
}
