#include "deque.h"

void	deque_push_back(t_deque *dq, void *content)
{
	t_deque_node	*node;

	node = malloc(sizeof(t_deque_node));
	if (!node)
		return ;
	node->content = content;
	node->prev = dq->tail;
	node->next = NULL;
	if (deque_is_empty(dq))
	{
		dq->head = node;
	}
	else
	{
		dq->tail->next = node;
	}
	dq->tail = node;
	dq->len++;
}

void	deque_push_front(t_deque *dq, void *content)
{
	t_deque_node	*node;

	node = malloc(sizeof(t_deque_node));
	if (!node)
		return ;
	node->content = content;
	node->next = dq->head;
	node->prev = NULL;
	if (deque_is_empty(dq))
	{
		dq->tail = node;
	}
	else
	{
		dq->head->prev = node;
	}
	dq->head = node;
	dq->len++;
}
