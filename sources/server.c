/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:10:26 by ljerinec          #+#    #+#             */
/*   Updated: 2023/05/02 14:01:06 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sigusr(int sig);

char	*g_str;

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	s_sigaction.sa_sigaction
	sigaction(SIGUSR1, &sigusr, 0);
	sigaction(SIGUSR2, &sigusr, 0);
	while (1)
	{
		usleep(1);
	}
	return (0);
}

void	sigusr(int sig)
{
	static int	bit = 0;
	static int	i = 0;

	if (sig == SIGUSR2)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		g_str = ft_strjoin(g_str, (char *)&i);
		if (i == 0 && g_str)
		{
			ft_printf("%s", g_str);
			free(g_str);
		}
		bit = 0;
		i = 0;
	}
}
