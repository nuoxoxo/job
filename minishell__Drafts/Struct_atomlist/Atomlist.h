#ifndef _ATOMLIST_H
# define _ATOMLIST_H

# include "Envlist.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include <readline/readline.h>
# include <readline/history.h>

# define WHITE_SPACE " \f\n\r\t\v" // for no reason tv
# define PROMPT "196883 ↯ "

// extern int	g_exit_status;

enum e_cmd_type
{
	T_ENV, // 0
	T_OFF,
	T_PIPE, // 2
	T_REDIR_IN,
	T_REDIR_HD,
	T_REDIR_OUT,
	T_REDIR_AP // 6
};

typedef struct	s_atom
{
	char			*str;
	struct	s_atom		*prev;
	struct	s_atom		*next;
	enum	e_cmd_type		type;
}	t_atom;

typedef struct	s_atomlist
{
	int			pipe_fd[2];
	pid_t			pid;
	t_env			*envlist;
	t_atom			*cmd;
	t_atom			*rdr_in;
	t_atom			*rdr_out;
	struct	s_atomlist	*prev;
	struct	s_atomlist	*next;
}	t_atomlist;

//	charset

void	charset_parse(char **line, char *charset, t_atom **stringlist);
void	charset_sort(t_atom **atom, char **line, int option);

//	t_atom / stringlist

char	*atom_create(char **line);
void	atom_len(char *line, int *len, int nquote);

t_atom	*stringlist_init(char *s);
t_atom	*stringlist_from_line(char *line, char *charset);
void	stringlist_from_envlist(t_atom *atom, t_env *envlist);
void	stringlist_append(t_atom **stringlist, t_atom *atom);
void	stringlist_trim(t_atom *atom);
void	stringlist_free(t_atom *node);
int	stringlist_get(char *line, t_atom **stringlist, t_env *envlist);
//int	stringlist_get(char *line, t_env *envlist);

void	stringlist_print(t_atom *node);

int	quote_trim_len(char *s);
void	quote_wrap(char **s, int *quote1, int *quote2, int *len);

void	quote_skip(char *s, int *i, int *squote);
char	*quote_trim(char *s);

//	checkers

int	check_whitespace(char *line);
int	check_quote(char *line);
int	check_pipeline(t_atom *atom);

//	libc

int	ft_strncmp(const char *str1, const char *str2, size_t n);
//char	*ft_strjoin2(char const *s1, char const *s2); // moved : Envlist.h
char	*ft_strchr(const char *s, int c);

#endif
