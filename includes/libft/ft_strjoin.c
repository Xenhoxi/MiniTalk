/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:13:20 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/27 12:35:31 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*chainjoin;
	size_t	i;
	size_t	u;

	i = -1;
	u = 0;
	if (s1 && s2)
		sizetotal = ft_strlen(s1) + ft_strlen(s2);
	if (s1 && !s2)
		sizetotal = ft_strlen(s1);
	if (!s1 && s2)
		sizetotal = ft_strlen(s2);
	chainjoin = malloc(sizeof(char) * sizetotal + 1);
	if (!chainjoin)
		return (NULL);
	if (s1)
		while (++i < ft_strlen(s1))
			chainjoin[i] = s1[i];
	if (s2)
		while (u < ft_strlen(s2))
			chainjoin[i++] = s2[u++];
	chainjoin[i] = '\0';
	return (chainjoin);
}
