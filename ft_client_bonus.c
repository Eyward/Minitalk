/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:20:50 by zzirh             #+#    #+#             */
/*   Updated: 2022/04/04 20:59:04 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

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

void	handler(int sig)
{
	(void)sig;
	ft_printf("message was successfully delivered\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3)
	{
		ft_printf("client:invalid arguments\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
		return (1);
	ft_send(pid, av[2], ft_strlen(av[2]));
}
