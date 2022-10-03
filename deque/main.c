#include "deque.h"
#include "stdio.h"

int	main()
{
	t_deque	*e;

	e = deque_init();
	int	n1 = 2;
	deque_push_back(e, &n1);
	int	n2 = 4;
	deque_push_back(e, &n2);
	int	n3 = 8;
	deque_push_back(e, &n3);

	printf("\n");
	deque_print(e);

	printf("head: %i \n", *(int*) (e->head->content));
	printf("tail: %i \n", *(int*) (e->tail->content));
	printf("len: %i \n", e->len);
	printf("\n");

	deque_print(e);

	printf("popped: %i \n", *(int*)deque_pop_back(e));
	printf("head: %i \n", *(int*) (e->head->content));
	printf("tail: %i \n", *(int*) (e->tail->content));
	printf("len: %i \n", e->len);
	printf("\n");

	deque_print(e);

	printf("popped: %i \n", *(int*)deque_pop_back(e));
	printf("head: %i \n", *(int*) (e->head->content));
	printf("tail: %i \n", *(int*) (e->tail->content));
	printf("len: %i \n", e->len);
	printf("\n");
	
	deque_print(e);
	printf("\n");

	return (0);
}
