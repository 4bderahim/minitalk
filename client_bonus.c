/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:41:36 by ael-krid          #+#    #+#             */
/*   Updated: 2024/05/10 18:41:37 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (r);
}

void	client_sig_handler(int sig, siginfo_t *info, void *vp)
{
	(void)vp;
	(void)info;
	if (sig == SIGUSR1)
	{
		write(1, "[+] MSG RECEIVED!\n", 18);
	}
}

void	sender(unsigned char s, int target_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (s & (1 << i))
			kill(target_pid, SIGUSR1);
		else
			kill(target_pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	send(int size, pid_t pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (size & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int					target_pid;
	int					i;
	struct sigaction	sa;

	if (ac == 3)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = client_sig_handler;
		sigaction(SIGUSR1, &sa, NULL);
		target_pid = ft_atoi(av[1]);
		if (!target_pid)
			return (0);
		send(ft_strlen(av[2]), target_pid);
		i = 0;
		while (av[2][i])
		{
			sender(av[2][i], target_pid);
			i++;
		}
	}
	return (0);
}
