/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:49:01 by zzirh             #+#    #+#             */
/*   Updated: 2022/04/01 14:59:23 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "f_Printf/ft_printf.h"

typedef struct t_signal
{
	unsigned char	buf;
	int				cmp;
	int				cid;

}	t_sig;

void	ft_send(int pid, char *s, int len);
void	handle_sigusr(int signum, siginfo_t *inf, void *a);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
