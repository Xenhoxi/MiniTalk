/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:10:26 by ljerinec          #+#    #+#             */
/*   Updated: 2023/05/04 16:23:35 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sigusr(int sig, siginfo_t *info, void *context);
char	*ft_strjoin_char(char *s1, char s2);

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	s_sigaction.sa_sigaction = sigusr;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
	{
		usleep(1);
	}
	return (0);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	int		sizetotal;
	char	*chainjoin;
	size_t	i;

	i = -1;
	if (s1 && s2)
		sizetotal = ft_strlen(s1) + 1;
	if (s1 && !s2)
		sizetotal = ft_strlen(s1);
	if (!s1 && s2)
		sizetotal = 1;
	chainjoin = malloc(sizeof(char) * (sizetotal + 1));
	if (!chainjoin)
		return (NULL);
	if (s1)
		while (++i < ft_strlen(s1))
			chainjoin[i] = s1[i];
	if (!s1)
		i++;
	if (s2)
		chainjoin[i] = s2;
	chainjoin[i + 1] = '\0';
	return (chainjoin);
}

void	error(int *bit, char *i, char *str)
{
	*bit = 0;
	*i = 0;
	if (str)
		free(str);
}

void	sigusr(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	i = 0;
	static char	*str = NULL;

	(void) info;
	(void) context;
	if (sig == SIGUSR2)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i >= 0x00 && i <= 0x7F)
			str = ft_strjoin_char(str, i);
		else
			exit(0);
		if (i == 0 || ft_strlen(str) > 1000)
		{
			ft_printf("%s", str);
			str = NULL;
			free(str);
		}
		bit = 0;
		i = 0;
	}
	(usleep(50), kill(info->si_pid, SIGUSR2));
}
