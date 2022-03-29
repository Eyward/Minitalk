/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:43:44 by zzirh             #+#    #+#             */
/*   Updated: 2022/03/29 22:39:59 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_send(int pid, char *s, int len)
{
	int	i;
	int	bit;

	i = 0;
	while (i <= len)
	{
		bit = 0;
		while (bit < 8)
		{
			if (!((s[i] >> bit) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("client:invalid arguments\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ft_send(pid, av[2], ft_strlen(av[2]));
	return (0);
}
