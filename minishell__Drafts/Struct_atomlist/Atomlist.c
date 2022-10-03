#include "Atomlist.h"
#include "Envlist.h"

// in main : stringlist_get(line, & stringlist, envlist);
//
// proto : stringlist_get(char *line, t_atom **stringlist, t_env *envlist);

int	stringlist_get(char *line, t_atom **atom, t_env *envlist)
{
	if (check_whitespace(line) || !check_quote(line)) // 2 checkers . done
		return 0;
	(*atom) = stringlist_from_line(line, " |<>"); // done .split line into atoms
	
	printf( color2 "here: strlst get, middle \n" noc );

	stringlist_from_envlist(*atom, envlist); // done
	stringlist_trim(*atom); // trim . done
	if (!(*atom) || !check_pipeline(*atom)) // in checkers . done
	{
		stringlist_free(*atom); // done
		return 0;
	}
	//stringlist_print(*atom);
	return 1;
}

void	stringlist_free(t_atom *node)
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

t_atom	*stringlist_from_line(char *line, char *charset)
{
	t_atom		*stringlist;
	char		*temp;

	printf( color1 "here: strlst from line upper \n" noc );

	stringlist = NULL;
	while (*line != '\0')
	{
		charset_parse(& line, charset, & stringlist); // cs parse . done

		temp = atom_create(& line); // create atom . done

		while (*line != '\0' && !ft_strchr(charset, *line))
			temp = ft_strjoin2(temp, atom_create(& line)); // sj2 . done

		printf( color1 "here: in strlst from line, after strjoin \n" noc );

		if (temp)
			stringlist_append(& stringlist, stringlist_init(temp));
			// stringlist_append . done
		printf( color1 "here: strlst from line lower \n" noc );
	}

	printf( color1 "here: strlst from line, out of while loop \n" noc );

	return (stringlist);
}

void	stringlist_from_envlist(t_atom *atom, t_env *envlist) // env to str
{
	char		*s;
	int		i;
	int		squote;

	printf( color2 "here: strlst from envlist, upper \n" noc );

	while (atom)
	{
		i = -1;
		squote = 196883;
		s = sdup2(atom->str);
		//while (s[++i])
		while (++i < slen(s))
		{
			printf( color1 
			"here: strlst from envlist, while loop s = %s, i = %d \n"
			noc , s, i);

			quote_skip(s, & i, & squote); // quote skip . done
			if (squote == 196883 && s[i] == '$')
			{
				atom->type = T_ENV; // in h . done
				atom->str = envlist_insert(envlist, atom->str, s + i);
				// envlist insert . done
			}

			printf( color1 
			"here: strlst from envlist, while loop s = %s, i = %d \n"
			noc , s, i);
		}
		printf("here: strlst from envlist, after while, atom->str: %s \n", atom->str);
		atom = atom->next;
		free(s);
	}
	printf( color2 "here: strlst from envlist, lower \n" noc );
}

void	stringlist_trim(t_atom *atom)
{
	char	*line;
	char	*temp;

	printf( color1 "here: trim \n" noc );

	while (atom)
	{
		temp = atom->str;
		line = quote_trim(atom->str); // done
		if (line)
		{
			atom->str = line;
			free(temp);
		}
		atom = atom->next;
		temp = NULL;
	}
}

void	charset_parse(char **line, char *charset, t_atom **stringlist)
{
	t_atom		*atom;

	printf( color1 "here: charset parse \n" noc);

	while (ft_strchr(charset, **line) && **line != '\0')
	{
		atom = NULL;
		if (!ft_strncmp(*line, "<<", 2) || !ft_strncmp(*line, ">>", 2))
			charset_sort(& atom, line, 2); // cs sort . done
		else if (ft_strchr("|<>", **line))
			charset_sort(& atom, line, 1); // idem . done
		if (atom)
			stringlist_append(stringlist, atom); // done
		(*line)++;
	}
}

void	charset_sort(t_atom **atom, char **line, int option)
{
	(*atom) = stringlist_init(sndup2(*line, option)); // strlist init . done
	if (option == 2)
	{
		if (**line == '<')
			(*atom)->type = T_REDIR_HD; // done
		else if (**line == '>')
			(*atom)->type = T_REDIR_AP;
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

	printf( color1 "here: atom create upper \n" noc );

	if (**line == '\0')
		return (NULL);
	len = 0;
	if (**line != '"' && **line != '\'')
		atom_len(*line, & len, 0); // count atom len . done
	else
		atom_len(*line, & len, 1);
	s = sndup2(*line, len);
	(*line) += len;
	printf( color1 "here: atom create lower \n" noc );
	return (s);
}

void	atom_len(char *line, int *len, int nquote)
{
	if (nquote == 1)
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
	}
	else
	{
		while (line[*len] != '\0'
			&& !ft_strchr(" <>|'\"", line[*len]))
		{
			if (ft_strncmp(line + *len, "\\\\", 2) == 0)
				(*len)++;
			else if (line[*len] == '\\'
				&& ft_strchr("'\"", line[*len + 1]))
				(*len)++;
			(*len)++;
		}
	}
}

//	stringlist

t_atom	*stringlist_init(char *s) // checked
{
	t_atom		*atom;

	atom = (t_atom *) malloc(sizeof(t_atom));
	if (!atom)
		err_alloc();
	atom->prev = NULL;
	atom->next = NULL;
	atom->type = T_OFF;
	atom->str = s;

	printf( color1 "here: strlst init \n" noc );

	return (atom);
}

void	stringlist_append(t_atom **stringlist, t_atom *atom)
{
	t_atom		*temp;

	printf( color1 "here: strlst append upper \n" noc );

	if (*stringlist == NULL)
	{
		(*stringlist) = atom;
	}
	else
	{
		temp = *stringlist;
		while ((*stringlist)->next)
		{
			*stringlist = (*stringlist)->next;
		}
		(*stringlist)->next = atom;
		atom->prev = (*stringlist);
		atom->next = NULL;
		*stringlist = temp;
	}

	printf( color1 "here: strlst append lower \n" noc );
}

void	stringlist_print(t_atom *node)
{
	if (!node)
		printf("(null)\n");
	while (node)
	{
		printf("%s(%d)", node->str, node->type);
		if (node->next)
			printf(" | ");
		else
			printf(" \033[0;33m.\033[0;37m\n");
		node = node->next;
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
		err_alloc();
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
	int	dquote;
	int	squote;

	len = 0;
	dquote = 196883;
	squote = 196883;
	while (*s)
	{
		if (*s == '"')
			quote_wrap(& s, & dquote, & squote, & len);
		else if (*s == '\'')
			quote_wrap(& s, & squote, & dquote, & len);
		else if (ft_strncmp(s, "\\\\", 2) == 0)
		{
			*(++s) = '\0';
			len++;
		}
		else if (*s == '\\')
			quote_wrap(& s, & dquote, & squote, & len);
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

void	quote_skip(char *s, int *i, int *squote)
{
	printf("here: Quote skip, start, i = %d \n", *i);

	if ((*i) == 0 && s[(*i)] == '\'')
		(*squote) *= -1;
	else if (ft_strchr("\\$\"", s[(*i)]) == 0 \
			&& s[(*i) + 1] == '\'')
	{
		(*i)++;
		(*squote) *= -1;
	}
	else if ((*squote) == 196883 && s[(*i)] == '$')
		return ;
	else
		(*i)++;

	printf("here: Quote skip, end, i = %d \n", *i);
}

//	checkers

int	check_whitespace(char *line)
{
	while (*line)
	{
		if (!ft_strchr(WHITE_SPACE, *line)) // strchr wh_space . done
			return (0);
		line++;
	}
	return (1);
}

int	check_quote(char *line)
{
	int	squote;
	int	dquote;

	squote = 196883;
	dquote = 196883;
	while (*line)
	{
		if (ft_strncmp(line, "\\\\", 2) == 0 || \
			ft_strncmp(line, "\\'", 2) == 0 || \
			ft_strncmp(line, "\\\"", 2) == 0)
		{
			line += 2;
			continue ;
		}
		if (dquote == 196883 && *line == '\'')
			squote = -squote;
		if (squote == 196883 && *line == '"')
			dquote = -dquote;
		line++;
	}
	if (squote + dquote > 0)
		return 1;
	return 0;
}

int	check_pipeline(t_atom *atom)
{
	int	option; // TODO . option is in fact `is___` ??

	option = 1;
	if (atom->type == T_PIPE) // T_PIPE
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
