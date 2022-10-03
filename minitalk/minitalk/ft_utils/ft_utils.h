/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nuo              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "stdlib.h"
# include "unistd.h"

int		ft_strlen(char *_);
int		ft_atoi(char *_);
char	*ft_strncat(char *___, char *__, int _);
char	*ft_strcat(char *__, const char *_);
char	*ft_strdup(char *_);
char	*ft_atob(char *__, int _);
char	ft_btoc(char *_);
void	ft_putnbr(int _);
void	ft_putstr(char *_);

#endif
