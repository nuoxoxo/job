#include "deque.h"

void	*deque_pop_back(t_deque *dq)
{
	if (deque_is_empty(dq))
	{
		return (NULL);
	}

	t_deque_node	*temp;
	void		*cont;

	temp = dq->tail;
	dq->tail = temp->prev;
	if (!dq->tail)
	{
		dq->head = NULL;
	}
	else
	{
		dq->tail->next = NULL;
	}
	cont = temp->content;
	free(temp);
	dq->len--;
	return (cont);
}

void	*deque_pop_front(t_deque *dq)
{
	if (deque_is_empty(dq))
	{
		return (NULL);
	}

	t_deque_node	*temp;
	void		*cont;

	temp = dq->head;
	dq->head = temp->next;
	if (!dq->head)
	{
		dq->tail = NULL;
	}
	else
	{
		dq->head->prev = NULL;
	}
	cont = temp->content;
	free(temp);
	dq->len--;
	return (cont);
}
