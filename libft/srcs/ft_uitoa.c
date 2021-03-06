/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 03:41:04 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/15 02:12:33 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int u)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	size = 1;
	i = u;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = '\0';
	while (size--)
	{
		tab[size] = u % 10 + '0';
		u /= 10;
	}
	return (tab);
}
