#include "mlx/mlx.h"
#include "stdio.h"

typedef struct s_vars {void *mlx; void *win;} t_vars;

int	key_hook(int _, t_vars *v);
int	close(int _, t_vars *v);
int	mouse_hook(int _, t_vars *v);

int	main(void)
{
	int	wide = 320;
	t_vars	v;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, wide, wide, "Hello, World!");

	mlx_key_hook(v.win, key_hook, &v);
	mlx_mouse_hook(v.win, mouse_hook, &v);
	//mlx_hook(v.win, 2, 1L << 0, close, &v);	/// this line = obsolete
	mlx_loop(v.mlx);
}

int	mouse_hook(int mousecode, t_vars *vars)
{
	(void)	vars;
	int	c = mousecode;

	if (c == 1)		printf("Left click! (%d) \n", c);
	else if (c == 3)	printf("Wheel says \"Hi!\" (%d) \n", c);
	else if (c == 2)	printf("Right click! (%d) \n", c);
	//	2 & 3 are reversed on mac
	else if (c == 4)	printf("Wheel up (%d) \n", c);
	else if (c == 5)	printf("Wheel down (%d) \n", c);
	else			printf("Clicked! (%d) \n", c);
	return 0;
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)	vars;
	int	c = keycode;

	if (c < 22 && c > 17)	printf("%d (%d) \n", c - 17, c);
	else if (c == 23)	printf("5 (%d) \n", c);
	else if (c == 22)	printf("6 (%d) \n", c);
	else if (c == 26)	printf("7 (%d) \n", c);
	else if (c == 28)	printf("8 (%d) \n", c);
	else if (c == 25)	printf("9 (%d) \n", c);
	else if (c == 29)	printf("zero! (%d) \n", c);
	else if (c == 123)	printf("Left! (%d) \n", c);
	else if (c == 126)	printf("Up! (%d) \n", c);
	else if (c == 124)	printf("Right! (%d) \n", c);
	else if (c == 125)	printf("Down! (%d) \n", c);	
	else if (c == 24)	printf("+= (%d) \n", c);
	else if (c == 27)	printf("-_ (%d) \n", c);
	else if (c == 33)	printf("{[ (%d) \n", c);
	else if (c == 30)	printf("}] (%d) \n", c);
	else if (c == 39)	printf("\"\' (%d) \n", c);
	else if (c == 41)	printf(":; (%d) \n", c);
	else if (c == 42)	printf("|\\ (%d) \n", c);
	else if (c == 43)	printf("<, (%d) \n", c);
	else if (c == 44)	printf("?/ (%d) \n", c);
	else if (c == 46)	printf("m!! (%d) \n", c);
	else if (c == 47)	printf(">. (%d) \n", c);
	else if (c == 48)	printf("tab! (%d) \n", c);
	else if (c == 49)	printf("space! (%d) \n", c);
	else
		printf("Keydown! (%d) \n", keycode);
	return 0 ;
}

int	close(int keycode, t_vars *v)
{
	if (keycode == 53)
	{
		printf("ESC! (%d) \n", keycode);
		mlx_destroy_window(v->mlx, v->win);
	}
	return 0;
}
