/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:09:52 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/24 11:06:40 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send(char *str);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_printf("Pid : %s\n", argv[1]);
	ft_printf("Msg : %s\n", argv[2]);
	return (0);
}

void	send(char *str)
{
	SIGUSR1
}
