#include "deque.h"

#include "stdio.h"

t_deque	*deque_init(void)
{
	t_deque	*dq;

	dq = malloc(sizeof(t_deque));
	if (!dq)
		return (NULL);
	dq->head = NULL;
	dq->tail = NULL;
	dq->len = 0;
	return (dq);
}

int	deque_is_empty(t_deque *dq)
{
	return (!dq->head || !dq->tail);
}

int	deque_len(t_deque *dq)
{
	return (dq->len);
}


///	need alt_printf

void	deque_print(t_deque *dq)
{
	t_deque_node	*node;

	node = dq->head;
	while (node)
	{
		printf("%d ", *(int*) node->content);
		node = node->next;
	}
	printf("end\n");
}
