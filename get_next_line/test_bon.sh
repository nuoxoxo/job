gcc -Wall -Werror -Wextra -D BUFFER_SIZE=16 *bon*.c -fsanitize=address && ./a.out $1
