#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdlib.h"
# include "string.h"
# include "stdio.h"
# include "sys/wait.h"
# include "fcntl.h"

void		XCQ_Parent(char **, char **, int[2]);
void		XCQ_Child(char **, char **, int[2]);
void		XCQ(char *, char **);
void		free_strlst(char **);
void		_exit_error_(char *);
void		_exit_usage_(void);

char		*path_finder(char *, char **);

int			read_input(char **);
int			len(char *);

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *prefix, char const *suffix);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

#endif
