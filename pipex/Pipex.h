#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdlib.h"
# include "string.h"
# include "stdio.h"
# include "sys/wait.h"
# include "fcntl.h"
# include "../libft/libft.h"

void		parent_process(char **, char **, int[2]);
void		child_process(char **, char **, int[2]);
void		exec_cmd(char *, char **);
void		free_argv(char **);
void		error_exit(char *);
void		usage(void);
int			read_input(char **);
int			len(char *);
char		*path_finder(char *, char **);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *prefix, char const *suffix);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

#endif
