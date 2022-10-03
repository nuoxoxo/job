#include "v6.h"

int	atomlist_get(char *line, t_atom **atom, t_env *envlist)
{
	// New: add input/line to history before any check

	add_history(line);

	if (check_string_isempty(line) || !check_quote_isvalid(line))
	{
		return 0;
	}
	(*atom) = atomlist_from_line(line, " |<>");
	// print_atomlist(*atom); // xcq debugging here

	atomlist_from_envlist(*atom, envlist);
	//print_atomlist(*atom);

	atomlist_trim(*atom);
	// print_atomlist(*atom); // xcq debugging here

	if (!(*atom) || !check_pipeline(*atom))
	{
		atomlist_free(*atom);
		ft_putstr_fd(PROMPT "syntax error near unexpected token \n",
				STDERR_FILENO);
		return 0;
	}
	// print_atomlist(*atom); // never reached if input :: cat _cmd.0 > > log
	return 1;
}

t_atom	*atomlist_new_node(char *s)
{
	t_atom		*atom;

	atom = (t_atom *) malloc(sizeof(t_atom));
	if (!atom)
		exit_error_alloc();
	atom->prev = null;
	atom->next = null;
	atom->type = T_OFF;
	atom->str = s;

	return (atom);
}

void	atomlist_append(t_atom **atomlist, t_atom *atom)
{
	t_atom		*head;

	if (*atomlist == null)
	{
		(*atomlist) = atom;
		return ;
	}
	head = *atomlist;
	while ((*atomlist)->next)
	{
		*atomlist = (*atomlist)->next;
	}
	(*atomlist)->next = atom;
	atom->prev = (*atomlist);
	atom->next = null;
	*atomlist = head;
}

void	atomlist_free(t_atom *node)
{
	t_atom		*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->str);
		temp->str = null;
		temp->next = null;
		free(temp);
		temp = null;
	}
}

t_atom	*atomlist_from_line(char *line, char *charset)
{
	t_atom		*atomlist;
	char		*temp;

	atomlist = null;
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
# include "sys/stat.h" // heredoc filename builder

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
				// print(color1 " atom.str = %s \n" noc, atom->str); // DBG

				atom->str = atomlist_getenv(envlist, atom->str, s + i);
				// print(color2 " atom.str = %s \n\n" noc, atom->str); // DBG
# include "sys/stat.h" // heredoc filename builder
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
		temp = null;
	}
}

char	*atom_create(char **line)
{
	int		len;
	char		*s;

	if (**line == '\0')
		return (null);
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

//	new

void	atomlist_cherrypick_append(t_atom **self, t_atom **other)
{
	t_atom		*temp;

	temp = (*self);
	(*self) = (*self)->next;
	temp->prev = null;
	temp->next = null;
	atomlist_append(other, temp);
}

//	new

void	atomlist_pop(t_atom **atom)
{
	t_atom		*temp;

	temp = (*atom);
	(*atom) = (*atom)->next;
	free(temp->str);
	free(temp);
}

//	new . for xcq

/*
int	atomlist_count_node(t_atom *node)
{
	int			res;

	res = 0;
	while (node)
	{
		node = node->next;
		++res;
	}
	return (res);
}
*/

//	cf. tokenlist_count_node

/*
int	tokenlist_count_node(t_token *node) // New
{
	int			res;

	res = 0;
	while (node)
	{
		res++;
		node = node->next;
	}
	return (res);
}
*/

char	**atomlist_to_arr(t_atom *node)
{
	char		**res;
	int			len;

	len = atomlist_count_node(node);
	res = (char **) malloc(sizeof(char *) * (len + 1));
	if (!res)
		exit_error_message("malloc");
	res[len] = NULL;
	len = 0;
	while (node)
	{
		res[len] = ft_strdup(node->str);
		if (!res[len])
			exit_error_message("malloc");
		len++;
		node = node->next;
	}
	return (res);
}
