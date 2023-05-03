/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:09:52 by ljerinec          #+#    #+#             */
/*   Updated: 2023/05/03 13:54:52 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	char_to_bit(int pid, char str);
void	receved(int sig, siginfo_t *info, void *context);
void	error(int sig, siginfo_t *info, void *context);

int		g_bool = 0;

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s_sigaction;

	i = 0;
	pid = ft_atoi(argv[1]);
	s_sigaction.sa_sigaction = error;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	if (argc != 3)
		return (0);
	while (argv[2][i])
	{
		if (g_bool == 1)
			break ;
		char_to_bit(pid, argv[2][i++]);
	}
	if (g_bool == 0)
		char_to_bit(pid, 0);
	return (0);
}

void	error(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		g_bool = 1;
}

void	char_to_bit(int pid, char str)
{
	int	i;
	int	result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = str % 2;
		if (result == 0)
			kill(pid, SIGUSR1);
		else if (result == 1)
			kill(pid, SIGUSR2);
		str = str / 2;
		i--;
		usleep(50);
	}
}
