#include <sys/stat.h>
#include <stdbool.h>
#include <stdio.h>

enum	class
{
	CLASS_OWNER,
	CLASS_GROUP,
	CLASS_OTHER
};

enum	permission
{
	PERMISSION_READ,
	PERMISSION_WRITE,
	PERMISSION_EXECUTE
};

const	mode_t EMPTY_MODE = 0;

mode_t	perm(enum class c, enum permission p)
{
	return 1 << ((3 - p) + (2 - c) * 3);
}

bool	mode_contains(mode_t mode, enum class c, enum permission p)
{
	return mode & perm(c, p);
}

mode_t	mode_add(mode_t mode, enum class c, enum permission p)
{
	return mode | perm(c, p);
}

mode_t	mode_rm(mode_t mode, enum class c, enum permission p)
{
	return mode & ~perm(c, p);
}

// buf must have at least 10 bytes

void	strmode(mode_t mode, char *buf)
{
	const char	chars[] = "rwxrwxrwx";
	size_t		i = -1;

	while (++i < 9)
	{
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
	}
	buf[9] = '\0';
}

int	main(void)
{
	size_t	num_examples;
	char	buf[10];
	size_t	i;

	mode_t	examples[] =
	{
		0, 0666, 0777, 0700, 0100, 01, 02, 03, 04, 05, 06, 07
	};
	num_examples = sizeof(examples) / sizeof(examples[0]);
	i = -1;
	while (++i < num_examples)
	{
		strmode(examples[i], buf);
		printf("%04o is %s\n", examples[i], buf);
	}
}
