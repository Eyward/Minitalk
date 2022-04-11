/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:23:26 by zzirh             #+#    #+#             */
/*   Updated: 2022/04/01 15:56:40 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include "f_Printf/ft_printf.h"

typedef struct t_signal
{
	unsigned char	buf;
	int				cmp;
	int				cid;

}	t_sig;

void	ft_send(int pid, char *s, int len);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	handle_sigusr_bonus(int signum, siginfo_t *inf, void *a);

#endif