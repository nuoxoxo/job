/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void    display_c_tail(char *filename, int offset, int index, int ac);
void    display_c_head(char *filename, int offset, int index, int ac);
void    display_default(char *filename, int index, int ac);
void    display_filename(char *filename);
void    display_stdout(void);

int     count_size_of_file(char *filename, int mode);
int     verify_argv_minus(char **argv);
int     verify_argv(int ac, char **av);
int     check_if_only_num(char *s);

void    msg(char *arg, int n);
int     atoi_easy(char *s);
int     len(char *s);

/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */
