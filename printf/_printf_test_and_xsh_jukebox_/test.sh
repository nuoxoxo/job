gcc -Wall -Wextra -Werror -fsanitize=address $1 && ./a.out && rm a.out
