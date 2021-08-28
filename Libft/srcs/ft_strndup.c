/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:05:22 by rcorenti          #+#    #+#             */
/*   Updated: 2021/08/14 06:05:25 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t size)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (size > i)
		size = i;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		ft_memcpy(str, s, size);
		str[size] = '\0';
	}
	return (str);
}