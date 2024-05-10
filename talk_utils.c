/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:46:57 by ael-krid          #+#    #+#             */
/*   Updated: 2024/05/10 18:46:58 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*all;
	size_t	tmp;
	size_t	i;

	if (count == 0 || size == 0)
	{
		all = (char *)malloc(count * size);
		all[0] = 0;
		return (all);
	}
	tmp = count * size;
	if ((tmp / size) != count)
		return (NULL);
	all = (char *)malloc(count * size);
	if (!all)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		all[i] = 0;
		i++;
	}
	return (all);
}

int	size_(int sig, int *size, int *ii)
{
	static int	size_num;
	int			i;

	i = *ii;
	if (i == 0)
	{
		size_num = 0;
	}
	if (sig == SIGUSR1)
	{
		size_num |= 1 << ((31 - i));
		i++;
	}
	if (sig == SIGUSR2)
		i++;
	if (i == 32)
	{
		i = 0;
		*size = 0;
		*size = size_num;
		*ii = i;
		return (*size);
	}
	*ii = i;
	return (0);
}

char	*catch_size_and_alloc(int sig, int *i, int *msg_allocated)
{
	static int	size;
	static char	*msg;

	size = size_(sig, &size, i);
	if (size > 0)
	{
		msg = (char *)ft_calloc(size + 1, sizeof(char));
		if (msg == NULL)
			exit(0);
		*msg_allocated = size;
		size = 0;
		return (msg);
	}
	return (NULL);
}
