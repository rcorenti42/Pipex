/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:18:27 by rcorenti          #+#    #+#             */
/*   Updated: 2019/10/28 19:07:01 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	c;
	long int	d;
	int			nb;

	c = 0;
	d = 0;
	nb = 0;
	while (str[c] == '\t' || str[c] == '\n' || str[c] == '\v' ||
			str[c] == '\f' || str[c] == '\r' || str[c] == ' ')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			d++;
		c++;
	}
	while ('0' <= str[c] && str[c] <= '9')
	{
		nb = nb * 10 + str[c] - '0';
		c++;
	}
	if (d % 2 == 1)
		nb = nb * -1;
	return (nb);
}
