/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:22:04 by rcorenti          #+#    #+#             */
/*   Updated: 2019/11/14 22:24:24 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n <= 0)
		return (0);
	while (x < (n - 1) && s1[x] == s2[x] && s1[x] && s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
