#ifndef _ENVLIST_H
# define _ENVLIST_H

# include "ft_toolkit.h"
# include "stdio.h"

# define noc	"\e[0;0m"
# define color2	"\e[0;33m" // yellow
# define color1	"\e[0;36m" // cyan
# define color3	"\e[0;32m" // green
# define color4 "\e[0;94m" // blue
# define white	"\e[0;37m"

//	the envlist struct
//	is a doubly linked list of key-value pairs of type char *-char *

typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env		*prev;
	struct s_env		*next;
}	t_env;

//		main methods

extern int		g_exit_status;

t_env		*envlist_new_node(char *, char *);
t_env		*envp_to_envlist(char **);
void		envlist_append(t_env **, t_env *);
void		envlist_erase(t_env **);
void		envlist_free(t_env *);
void		envlist_print(t_env *);
int		envlist_replace(t_env *, char *, char *);
char		**envlist_to_arr(t_env *envl);

//	additional methods

char		*envlist_get_val(t_env *node, char *key);
char		*envlist_get_key(char *); // New
int		envlist_has_key(t_env *node, char *key);

/*	toolkit extended	*/

char		*ft_strndup_protected(const char *src, int n);
char		*ft_strdup_protected(const char *src);
char		*ft_strjoin_protected(char const *prefix, char const *suffix);

/*		New		*/

char		*ft_strjoin_triple(char *, char *, char *);








#endif
