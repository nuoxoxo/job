#ifndef _ENVLIST_H
# define _ENVLIST_H

# include "ft_toolkit.h"
# include "stdio.h"

# define noc	"\e[0;0m"
# define color2	"\e[0;33m"
# define color1	"\e[0;36m"
# define color3	"\e[0;32m"
# define colorp "\e[0;95m" // PROMPT
# define white	"\e[0;37m"

# define red "\e[0;91m"
# define whi "\e[0;97m"
# define blu "\e[0;94m"


//	the envlist struct
//	is a doubly linked list of key-value pairs of type char *-char *

typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env		*prev;
	struct s_env		*next;
}	t_env;

//	methods 1

extern int			g_exit_status;

t_env		*envlist_new_node(char *, char *);
t_env		*envp_to_envlist(char **);
void		envlist_append(t_env **, t_env *);
void		envlist_erase(t_env **);
void		envlist_free(t_env *);
void		envlist_print(t_env *);
int			envlist_replace(t_env *, char *, char *);

//	additional methods

char		*envlist_get_val(t_env *envlist, char *key);
char		*envlist_get_key(char *);

/*	toolkit extended	*/

char		*ft_strndup_protected(const char *src, int n);
char		*ft_strdup_protected(const char *src);
char		*ft_strjoin_protected(char const *prefix, char const *suffix);

#endif
