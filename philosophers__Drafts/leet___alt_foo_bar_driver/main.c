/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "semaphore.h"
#include "pthread.h"
#include "unistd.h"
#include "stdio.h" /* scanf */
#include "stdlib.h"

typedef struct 
{
    int         n;

    sem_t       foo_; // added
    sem_t       bar_; // added
    
} FooBar;


FooBar*		fooBarCreate(int);
void		fooBarFree(FooBar*); /* destroy semaphores */
void		*foo(void *);
void		*bar(void *);

/*
 * 	
 * 	*sem_init . sem_close not workig on osx		
 *	*to retry on ubu
 *
 */
/*
 *
 *
 *	Unnamed POSIX semaphores are not supported on OSX. 
 *	You need to use named semaphores.
 *
 *	Use sem_open instead of sem_init. 
 *	Don't use sem_destroy but rather sem_close and sem_unlink.
 *
 *
 */

//	drive

int	main()
{

	pthread_t		a;
	pthread_t		b;
	FooBar			*obj;
	int			n;

	scanf("%d", & n);
	obj = fooBarCreate(n);
	pthread_create(& a, NULL, & foo, obj);
	pthread_create(& b, NULL, & bar, obj);
	pthread_join(a, NULL);
	pthread_join(b, NULL);
	fooBarFree(obj);
}

//

FooBar*		fooBarCreate(int n)
{
	FooBar	*obj;

	obj = (FooBar *) malloc(sizeof(FooBar));
	obj->n = n;
	sem_init(& obj->foo_, 0, 0);
	sem_init(& obj->bar_, 0, 1);
	sem_open(& obj->foo_, 0, 0);
	sem_open(& obj->bar_, 0, 1); 
	return (obj);
}

void	*foo(void *o)
{
	FooBar		*obj;
	int		i;

	obj = (FooBar *) o;
	i = -1;
	while (++i < obj->n)
	{
		sem_wait(& obj->bar_);
		//printFoo();
		write(1, "foo", 3);
		sem_post(& obj->foo_);
	}
	return (NULL);
}

void	*bar(void *o)
{
	FooBar		*obj;
	int		i;

	obj = (FooBar *) o;
	i = -1;
	while (++i < obj->n)
	{
		sem_wait(& obj->foo_);
		//printBar();
		write(1, "bar", 3);
		write(1, "foo", 3);
		sem_post(& obj->bar_);
	}
	return (NULL);
}

void	fooBarFree(FooBar *obj)
{
	sem_destroy(& obj->foo_);
	sem_destroy(& obj->bar_);
	free(obj);
}
