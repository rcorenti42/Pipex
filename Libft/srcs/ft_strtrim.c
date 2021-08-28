/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 02:24:53 by rcorenti          #+#    #+#             */
/*   Updated: 2019/11/20 23:01:14 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_setcmp(const char c, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == c)
			j++;
		i++;
	}
	if (j == 0)
		return (0);
	return (1);
}

static	char	*ft_zero(char *str)
{
	if (!(str = malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = -1;
	str = NULL;
	while (ft_setcmp(s1[i], set) == 1)
		i++;
	if (s1[i])
	{
		j = ft_strlen(s1) - 1;
		while (ft_setcmp(s1[j], set) == 1)
			j--;
		if (!(str = malloc(sizeof(char) * (j - i + 2))))
			return (NULL);
		while (++k < j - i + 1)
			str[k] = s1[i + k];
		str[k] = '\0';
	}
	else if (!(str = ft_zero(str)))
		return (NULL);
	return (str);
}
