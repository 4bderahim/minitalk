/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:46:42 by ael-krid          #+#    #+#             */
/*   Updated: 2024/05/10 18:46:48 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	add_char(char c, char **s)
{
	int		i;
	char	*msg;

	msg = *s;
	i = 0;
	while (msg[i] != 0)
	{
		i++;
	}
	msg[i] = c;
	*s = msg;
}

void	reset_i_and_c(int *i, unsigned char *c)
{
	if (*i != 0)
		return ;
	*i = 8;
	*c = 0;
}

void	print_msg_and_free(char *msg, siginfo_t *info, int action)
{
	putstr(msg);
	free(msg);
	if (action)
	{
		kill(info->si_pid, SIGUSR1);
	}
}
