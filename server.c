/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:47:09 by ael-krid          #+#    #+#             */
/*   Updated: 2024/05/10 18:47:10 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int		g_msg_allocated;

void	put_pid(pid_t pid)
{
	char	r;

	if (pid > 9)
		put_pid(pid / 10);
	r = pid % 10 + '0';
	write(1, &r, 1);
}

void	face_the_speaker(siginfo_t *info, pid_t *c_pid, int *i, char *msg)
{
	if (info->si_pid != *c_pid)
	{
		*c_pid = info->si_pid;
		*i = 0;
		if (g_msg_allocated != 0)
		{
			g_msg_allocated = 0;
			free(msg);
		}
	}
}

void	signal_handler(int sig_num, siginfo_t *info, void *vp)
{
	static pid_t			client_pid;
	static unsigned char	c;
	static int				i;
	static char				*msg;

	face_the_speaker(info, &client_pid, &i, msg);
	if (g_msg_allocated == 0)
	{
		msg = catch_size_and_alloc(sig_num, &i, &g_msg_allocated);
		return ;
	}
	(void)vp;
	reset_i_and_c(&i, &c);
	if (sig_num == SIGUSR1 || sig_num == SIGUSR2)
	{
		if (sig_num == SIGUSR1)
			c |= 1 << (i - 1);
		i--;
	}
	if (i == 0)
	{
		add_char(c, &msg);
		if (--g_msg_allocated == 0)
			print_msg_and_free(msg, info, 0);
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "[!] PID: ", 9);
	put_pid(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
