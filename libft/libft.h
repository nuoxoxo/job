/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2022/11/11 14:42:08 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdlib.h"
# include "unistd.h" // size_t dependency

/*****  Libc ( 12 + 9 + 2  = 23)  *********************************************/

///	is . to

int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

///	str

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *des, const char *src, size_t size);
char	*ft_strnstr(const char *huge, const char *tiny, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *s);

///	mem

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *destination, int c, size_t n);
void	*ft_memcpy(void *des, const void *src, size_t n);
void	*ft_memmove(void *des, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

///	mem+

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);

/*****  Additional ( 6 + 4 + 1 = 11 ) * ***************************************/

///	str

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *charset);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));

///	put

void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

///	itoa

char	*ft_itoa(int n);

/*****  Bonus - linked list ( 9 ) *********************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del) (void*));
void	ft_lstclear(t_list **lst, void (*del) (void*));
void	ft_lstiter(t_list *lst, void (*f) (void *));
void	ft_lstadd_front(t_list **lst, t_list *p);
void	ft_lstadd_back(t_list **lst, t_list *p);

#endif
