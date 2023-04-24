/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:10:26 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/24 15:15:23 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	usr1(int sig);
void	usr2(int sig);

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	while (1)
	{
		usleep(1);
	}
	return (0);
}

void	usr1(int sig)
{
	(void) sig;
	ft_printf("0");
}

void	usr2(int sig)
{
	(void) sig;
	ft_printf("1");
}
