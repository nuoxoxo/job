#include "v5.h"

int	atomlist_get(char *line, t_atom **atom, t_env *envlist)
{
	// New: add input/line to history before any check

	add_history(line); // New

	if (check_string_isempty(line) || !check_quote_isvalid(line))
	{
		return 0;
	}

	(*atom) = atomlist_from_line(line, " |<>");
	//atomlist_print(*atom);

	atomlist_from_envlist(*atom, envlist);
	//atomlist_print(*atom);

	atomlist_trim(*atom);
	//atomlist_print(*atom);

	if (!(*atom) || !check_pipeline(*atom))
	{
		atomlist_free(*atom);
		return 0;
	}
	// atomlist_print(*atom);
	return 1;
}

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
		return ;
	}
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
			temp = ft_strjoin_protected(temp, atom_create(& line));
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
		single_quote = 1;
		s = ft_strdup_protected(atom->str);
		while (++i < (int) slen(s))
		{
			quote_skip(s, & i, & single_quote);
			/* Index tracking test */

			/*
			print("inside: i = %d, sq(') = %d, c = %c \n",
				i, single_quote, s[i]);	// debugger
			*/

			if (single_quote == 1 && s[i] == '$')
			{
				atom->type = T_ENV;
				// debugger
				// print(color1 " atom.str = %s \n" noc, atom->str);
				atom->str = atomlist_getenv(envlist, atom->str, s + i);
				// debuger
				// print(color2 " atom.str = %s \n\n" noc, atom->str);
			}
		}
		atom = atom->next;
		free(s);
	}
}

char	*atomlist_getenv(t_env *envlist, char *atomstr, char *afterdollor)
{
	int		len;
	int		i; // i is a pointer to find '$'
	char		*key;
	char		*val;
	char		*res;

	key = envlist_get_key(afterdollor);
	len = slen(key);
	i = 0;
	while (atomstr[i] && atomstr[i] != '$' && ++i)
		;
	if (len == 0 && ft_strcmp(atomstr + i, "$") == 0)
	{
		free(key);
		return (atomstr);
	}
	val = envlist_get_val(envlist, key);
	if (atomstr[i] == '$' && atomstr[i + 1] && atomstr[i + 1] == '$'
		&& ++i)
		;
	// debugger . 2 lines
	// print(white "possible quote: " noc);
	// print(color3  "%s \n" noc, ft_strndup_protected(atomstr, i));
	res = ft_strjoin_protected(ft_strndup_protected(atomstr, i), val);
	// debugger . 2 lines
	// print(white "replace atom.str: " noc);
	// print(color3 "%s \n" noc, res);
	res = ft_strjoin_protected(res, ft_strdup_protected(atomstr + i + len + 1));
	// debugger . 2 lines
	// print(white "join until quote: " noc);
	// print(color3 "%s \n" noc, res);
	free(atomstr);
	free(key);
	return (res);
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
	s = ft_strndup_protected(*line, len);
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

void	atomlist_print(t_atom *node)
{
	if (!node)
	{
		print("(null)\n");
		return ;
	}
	while (node)
	{
		print( color1 "(type: %d) " noc , node->type);
		print( color2 "%s " noc , node->str);
		if (node->next)
			print("\n");
		else
			print("\n(end) \n");
		node = node->next;
	}
}

//	new

void	atomlist_cherrypick_append(t_atom **self, t_atom **other)
{
	t_atom		*temp;

	temp = (*self);
	(*self) = (*self)->next;
	temp->prev = NULL;
	temp->next = NULL;
	atomlist_append(other, temp);
}
