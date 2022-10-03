#ifndef DEQUE_H
# define DEQUE_H

# include "stdlib.h"

typedef struct	s_deque
{
	struct	s_deque_node	*head;
	struct	s_deque_node	*tail;
	int	len;

}	t_deque;

typedef	struct	s_deque_node
{
	struct	s_deque_node	*prev;
	struct	s_deque_node	*next;
	void	*content;

}	t_deque_node;

t_deque	*deque_init(void);
void	deque_push_front(t_deque *__, void *_);
void	deque_push_back(t_deque *__, void *_);
void	*deque_pop_front(t_deque *_);
void	*deque_pop_back(t_deque *_);
int	deque_is_empty(t_deque *_);
int	deque_len(t_deque *_);

void	deque_print(t_deque *_);

#endif
