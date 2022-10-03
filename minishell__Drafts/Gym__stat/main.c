#include "stdio.h"
#include "sys/stat.h"

#define stm "/* File type and mode */"
#define ino "/* Inode number */"
#define nl "\n"
#define nl2 "\n\n"

int	main()
{
	// Make a pointer to stat struct

	struct stat	file_info;
	struct stat	makef_info;
	struct stat	other_info;
	int		ok;

	// Make a stat system call

	ok = stat("main.c", & file_info);
	printf("ok = %d " nl, ok);

	ok = stat("Makefile", & makef_info);
	printf("ok = %d " nl, ok);

	ok = stat("a_random_file", & other_info);
	printf("ok = %d " nl2, ok);

	// st_mode
	// %o format specifier to display the value of an octal variable

	printf("main st_mode = %o " stm nl, file_info.st_mode);
	printf("makef st_mode = %o " stm nl2, makef_info.st_mode);

	// st_ino
	
	printf("main st_ino = %llo " ino nl, file_info.st_ino);
	printf("makef st_ino = %llo " ino nl2, makef_info.st_ino);

	// *Access a file that is not there 
	
	printf("a non-existent file's " nl);
	printf("st_mode = %o " stm nl, other_info.st_mode);
	printf("st_ino = %llo " ino nl2, other_info.st_ino);
}
