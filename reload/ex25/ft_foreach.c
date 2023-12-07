/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_foreach(int *tab, int length, void(*f)(int))
{
        int     i;

        i = -1;
        while (++i < length)
        {
            f(tab[i]);
        }
}

/*

// DRIVE

#include <unistd.h>
#include <stdio.h>

void    print_board(int side, int *arr);
void    print_one_digit(int n);

int     main(void)
{
        char    c;
        int     side = 9;
        int     board[] = {
                1, 2, 3, 4, 5, 6, 7, 8, 9,\
                7, 8, 9, 1, 2, 3, 4, 5, 6,\
                4, 5, 6, 7, 8, 9, 1, 2, 3,\
                3, 1, 2, 8, 4, 5, 9, 6, 7,\
                6, 9, 7, 3, 1, 2, 8, 4, 5,\
                8, 4, 5, 6, 9, 7, 3, 1, 2,\
                2, 3, 1, 5, 7, 4, 6, 9, 8,\
                9, 6, 8, 2, 3, 1, 5, 7, 4,\
                5, 7, 4, 9, 6, 8, 2, 3, 1};
        
        print_board(side, board);
        while (1)
        {
            fflush(stdin);
            printf("\nPrint all numbers in this board?");
            printf("\n(Press enter to continue...)");
            c = getchar();
            if (c == 'n')   break;
            printf("\napply print_one_digit(): \n");
            ft_foreach(board, side * side, &print_one_digit);
            printf("\n\n--\n");
        }
}

void    print_board(int side, int *board)
{
        int     i = -1, j, n;

        i = 0;
        write(1, "--\n", 3);
        while (i < side * side)
        {
            j = -1;
            while (++j < side)
            {
                n = board[i + j];
                print_one_digit(n);
            }
            write(1, "\n", 1);
            i += j;
        }
        write(1, "--\n", 3);
}

void    print_one_digit(int n)
{
        char    c;

        if (n < 10 && n > -1)
        {
            c = n % 10 + '0';
            write(1, &c, 1);
            write(1, " ", 1);
        }
}

*/
