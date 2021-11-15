/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 00:47:47 by rcorenti          #+#    #+#             */
/*   Updated: 2019/10/26 15:21:35 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	while (len > 0 && str[len] != c)
		len--;
	if (str[len] == c)
		return ((char *)str + len);
	else
		return (NULL);
}
