#ifndef _ATOMLIST_H
# define _ATOMLIST_H

# include "ft_toolkit.h"
# include "Envlist.h"
# include "stdio.h"
# include "readline/readline.h"
# include "readline/history.h"

# define WHITE_SPACE " \f\n\r\t\v" // for no reason tv

# define PROMPT color2 " (° ʖ °) " noc
// # define PROMPT color2 " ↯ " noc

enum e_cmd_type
{
	T_ENV, // 0
	T_OFF,
	T_PIPE, // 2
	T_REDIR_IN,
	T_HEREDOC,
	T_REDIR_OUT,
	T_APPEND // 6
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
	t_atom			*REDIR_IN;
	t_atom			*REDIR_OUT;
	struct	s_atomlist	*prev;
	struct	s_atomlist	*next;
}	t_atomlist;

//	charset

void		charset_parse(char **line, char *charset, t_atom **atomlist);
void		charset_assign(t_atom **atom, char **line, int option);

//	t_atom / atomlist

char		*atom_create(char **line);
void		atom_len(char *line, int *len, int n_quote);

t_atom		*atomlist_new_node(char *s);
t_atom		*atomlist_from_line(char *line, char *charset);
void	atomlist_from_envlist(t_atom *atom, t_env *envl);
char	*atomlist_getenv(t_env *elst, char *s1, char *s2); // mov fr. elst.h
void	atomlist_append(t_atom **alst, t_atom *atom);
void	atomlist_trim(t_atom *atom);
void	atomlist_free(t_atom *node);
int		atomlist_get(char *line, t_atom **alst, t_env *envl);

void	atomlist_print(t_atom *node);

int		quote_trim_len(char *s);
void	quote_wrap(char **s, int *quote1, int *quote2, int *len);

void	quote_skip(char *s, int *i, int *single_quote);
char	*quote_trim(char *s);

//	checkers

int		check_quote_double_vs_single(int, char);
int		check_quote_single_vs_double(int, char);
int		check_quote_isvalid(char *);
int		check_char_isescaped(char *);
int		check_string_isempty(char *);
int		check_pipeline(t_atom *);

//	printers

void	print_default_type_enum(void);
void	print_invalid_quote(int sq, int dq);

//	libc

int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
