#ifndef _v6_H
# define _v6_H

# include "ft_toolkit.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "stdio.h"
# include "sys/wait.h"
# include "sys/stat.h" // heredoc filename builder
# include "fcntl.h" // heredoc
# include "errno.h"
# include "string.h" // strerror

# include "signal.h" // bizarre: without this line still compiles

//  Colors
# define color5	"\e[1;36m" // cyan bold
# define color2	"\e[0;33m" // yellow
# define color1	"\e[0;36m" // cyan
# define color3	"\e[0;32m" // green
# define color4 "\e[0;94m" // blue
# define color0	"\e[0;37m"
# define noc "\e[0;0m"
# define null NULL
# define nl2 "\n\n"
# define nl "\n"


# define WHITE_SPACE		" \f\n\r\t\v" // For No Reason TV
//# define PROMPT			color3 "(° ʖ °) : "  noc
# define PROMPT			color3 "(° ʖ °)$ "  noc
# define PROMPT2		color3 " ↯ " noc

//	the elst is a doubly linked list of ch*.ch* key-value pairs 

typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env		*prev;
	struct s_env		*next;
}	t_env;

//	(in builtin)
//	none
//	exit pipe
//	exit

enum	e_builtin
{
	NONE,
	PWD,
	ENV,
	ECHO,
	CD,
	EXPORT,
	UNSET,
	EXIT,
	EXIT_INSIDE_PIPE
};

enum	e_cmd_type
{
	T_ENV, // 0
	T_OFF,
	T_PIPE, // 2
	T_REDIR_IN,
	T_HEREDOC,
	T_REDIR_OUT,
	T_APPEND // 6
};

enum	e_sig_mode
{
	READLINE,
	HEREDOC,
	SIG_WAIT
};

typedef struct	s_atom
{
	char			*str;
	struct	s_atom		*prev;
	struct	s_atom		*next;
	enum	e_cmd_type		type;
}	t_atom;

typedef struct	s_token
{
	int						pipe_fd[2];
	pid_t					pid;
	t_env					*envlist;
	t_atom					*cmd;
	t_atom					*REDIR_IN;
	t_atom					*REDIR_OUT;
	struct	s_token		*prev;
	struct	s_token		*next;
}	t_token ;

extern int		g_exit_status;

/*	toolkit extended	*/

char		*ft_strndup_protected(const char *src, int n);
char		*ft_strdup_protected(const char *src);
char		*ft_strjoin_protected(char const *prefix, char const *suffix);

/*		New		*/
char		*ft_strjoin_triple(char *, char *, char *);

/*		New		*/
void		exit_error_message(char *); // need errno.h

//	builtin

enum e_builtin		builtin_typeof(t_atom *cmd, t_token *token); // New

//  	envlist

t_env		*envlist_new_node(char *, char *);
t_env		*envp_to_envlist(char **);
char		**envlist_to_arr(t_env *envl);
char		*envlist_get_val(t_env *node, char *key);
char		*envlist_get_key(char *); // New
void		envlist_append(t_env **, t_env *);
void		envlist_erase(t_env **);
void		envlist_free(t_env *);
void		envlist_print(t_env *);
int			envlist_has_key(t_env *node, char *key);
int			envlist_replace(t_env *, char *, char *);

//  	New: singal handler

void		handle_signal(enum e_sig_mode mode);

//	t_atom / atomlist

int			atomlist_get(char *line, t_atom **slst, t_env *elst);
t_atom		*atomlist_from_line(char *line, char *charset);
t_atom		*atomlist_new_node(char *s);
char		*atomlist_getenv(t_env *elst, char *s1, char *s2);
char		*atom_create(char **line);
void		atom_len(char *line, int *len, int n_quote);
void		atomlist_from_envlist(t_atom *atom, t_env *elst);
void		atomlist_append(t_atom **slst, t_atom *atom);
void		atomlist_trim(t_atom *atom);
void		atomlist_free(t_atom *node);
void		atomlist_cherrypick_append(t_atom **self, t_atom **other); // new
void		atomlist_pop(t_atom **atom); // new

//	t_token / tokenlist

int		tokenlist_get(t_token **r, t_atom *h, t_env *elst);
void		tokenlist_from_atomlist(t_token *, t_atom **);
void		tokenlist_append(t_token **, t_token *);
void		tokenlist_free(t_token *head); // new
t_token		*tokenlist_from_envlist(t_env *);

//	heredoc

int		heredoc_1st_layer(t_token *_);
// static int	Heredoc_2nd_Layer(t_token *node); // file scope
//char		*Heredoc_Path_Builder(int num); // File scope
int		heredoc_3rd_layer(t_atom *node, char *filename);
void		heredoc_unlink(t_token *node);


//	checkers

int			check_quote_double_vs_single(int, char);
int			check_quote_single_vs_double(int, char);
int			check_quote_isvalid(char *);
int			check_char_isescaped(char *);
int			check_string_isempty(char *);
int			check_pipeline(t_atom *);

//	charset parsers

void		charset_parse(char **line, char *charset, t_atom **atomlist);
void		charset_assign(t_atom **atom, char **line, int option);

//  	quote parsers

void		quote_wrap(char **s, int *q1, int *q2, int *len);
void		quote_skip(char *s, int *i, int *single_quote);
int			quote_trim_len(char *s);
char		*quote_trim(char *s);

//	printers

void		print_default_type_enum(void);
void		print_invalid_quote(int sq, int dq);
void		print_char_star_array(char **);
void		print_input(char *);
void		print_atomlist(t_atom *node); // mvd from print_atomlist
void		print_tokenlist(t_token *node); // new printer
void		print_atom(t_atom *node); // new printer
void		print_builtin_type(enum e_builtin b); // new printer

#endif

///
