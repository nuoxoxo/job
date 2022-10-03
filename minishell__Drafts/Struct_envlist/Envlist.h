#ifndef _ENVLIST_H
# define _ENVLIST_H

# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

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

int			g_exit_status;

t_env		*envp_to_envlist(char **, t_env *); // now 2 params, v2 takes 1
t_env		*envlist_new_node(char *, char *);
void		envlist_append(t_env **, t_env *);
void		envlist_erase(t_env **);
void		envlist_free(t_env *);
void		envlist_print(t_env *);
int			envlist_replace(t_env *, char *, char *);

//	TODO . additional methods

/*	sdup set w. global error mgmt . named as str(n)dup2	*/

char		*sndup2(const char *src, int n);
char		*sdup2(const char *src);

void		err_alloc(void);

int		ft_strcmp(const char *s1, const char *s2);
void		ft_putendl_fd(char *s, int fd);

#endif
