/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:21:28 by zzirh             #+#    #+#             */
/*   Updated: 2022/04/02 19:09:05 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_sig	g_msg;

void	setter(void)
{
	g_msg.cmp = 0;
	g_msg.buf = 0;
	g_msg.cid = 0;
}

void	handle_sigusr_bonus(int signum, siginfo_t *inf, void *a)
{
	(void)a;
	if (inf->si_pid != g_msg.cid)
	{
		setter();
	}
	g_msg.buf = g_msg.buf + ((signum & 1) << g_msg.cmp);
	g_msg.cmp = g_msg.cmp + 1;
	if (g_msg.cmp == 8)
	{
		ft_printf("%c", g_msg.buf);
		if (!g_msg.buf)
		{
			kill(inf->si_pid, SIGUSR2);
		}
		setter();
	}
	g_msg.cid = inf->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("BONUS SERVER PID:%d\n", getpid());
	sa.sa_sigaction = &handle_sigusr_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		sleep(1);
}
