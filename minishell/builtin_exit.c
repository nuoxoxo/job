#include "v6.h"

#define MAX_LL 9223372036854775807

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 
◦ export without any options 
◦ unset without any options 
◦ env 	without any options and any arguments 
◦ exit 	without any options 	::: Here :::
*/

static void		builtin_exit_error_arg_non_num(char *arg);
static void		builtin_exit_error_arg_not_one(void);
static int		builtin_exit_get_code(char *arg);

void	builtin_exit(t_atom *node, int type)
{
	if (type != EXIT_INSIDE_PIPE || node->next == null)
	{
		ft_putstr_fd("exit \n", STDOUT_FILENO);
	}
	if (node->next == null)
	{
		g_exit_status = 0;
		exit(g_exit_status);
	}
	else if (!check_longlong_isvalid(node->next->str))
	{
		builtin_exit_error_arg_non_num(node->next->str);
	}
	else if (node->next->next)
	{
		builtin_exit_error_arg_not_one();
	}
	else
	{
		g_exit_status = builtin_exit_get_code(node->next->str);
		exit(g_exit_status);
	}
}

//

static void	builtin_exit_error_arg_non_num(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	g_exit_status = 255;
	exit(255);
}

static void	builtin_exit_error_arg_not_one(void)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
	g_exit_status = 1;
	exit(1);
}

static int	builtin_exit_get_code(char *s)
{
	unsigned long long	res;
	int					sign;

	sign = 1;
	res = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s != '\0' && ft_isdigit(*s) == 1)
	{
		res += (*s) - '0';
		if (ft_isdigit(*(s + 1)) == 1 && *(s + 1) != '\0')
			res *= 10;
		s++;
	}
	if ((sign == 1 && res > MAX_LL) || (sign == -1 && res - 1 > MAX_LL))
		builtin_exit_error_arg_non_num(s);
	return ((res * sign) & 255);
}

//	builtin Exit()'s get_code helper func - a version with printer

/*
int	builtin_exit_get_code(char *s)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s != '\0' && ft_isdigit(*s) == 1)
	{
		num += (*s) - '0';
		if (ft_isdigit(*(s + 1)) == 1 && *(s + 1) != '\0')
			num *= 10;
		s++;
	}
	if ((sign == 1 && num > MAX_LL) || (sign == -1 && num - 1 > MAX_LL))
		builtin_exit_error_arg_non_num(s);
	printf(color2 "sign: %d, num: %llu, (sign * num) = %llu \n",
		sign, num, sign * num);
	printf("(sign * num) & 255 = %llu \n" noc, (sign * num) & 255);
	return ((sign * num) & 255);
}
*/
