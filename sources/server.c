/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:10:26 by ljerinec          #+#    #+#             */
/*   Updated: 2023/05/02 12:34:18 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sigusr(int sig);

char	*g_str;

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, sigusr);
	signal(SIGUSR2, sigusr);
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
		if (i == 0)
		{
			ft_printf("%s\n", g_str);
			free(g_str);
		}
		g_str = ft_strjoin(g_str, (char *)&i);
		bit = 0;
		i = 0;
	}
}
