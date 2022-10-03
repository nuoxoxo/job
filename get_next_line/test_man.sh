gcc -Wall -Werror -Wextra -D BUFFER_SIZE=32 test_man.c get_next_line.c get_next_line_utils.c -fsanitize=address && ./a.out $1 $2
