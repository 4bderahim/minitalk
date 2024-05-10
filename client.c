#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (r);
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
		usleep(200);
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
	int	target_pid;
	int	i;

	if (ac == 3)
	{
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
