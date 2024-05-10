/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:47:53 by ael-krid          #+#    #+#             */
/*   Updated: 2024/05/10 18:47:59 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*catch_size_and_alloc(int sig, int *i, int *msg_allocated);
void	reset_i_and_c(int *i, unsigned char *c);
void	print_msg_and_free(char *msg, siginfo_t *info, int action);
void	add_char(char c, char **s);
#endif
