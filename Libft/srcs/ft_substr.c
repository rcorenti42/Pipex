/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:23:20 by rcorenti          #+#    #+#             */
/*   Updated: 2019/11/20 23:00:06 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*newchain;
	size_t	x;
	int		temp;
	size_t	ssize;

	newchain = NULL;
	x = 0;
	ssize = ft_strlen(s);
	if (start > ssize || s[ssize])
		temp = 1;
	(len > ssize - start) ? (temp = (int)ssize - start)
		: (temp = (int)len + 1);
	if (!(newchain = malloc(sizeof(char) * temp)))
		return (NULL);
	while (len > 0 && s[x + start] && (!(start > ssize || s[ssize])))
	{
		newchain[x] = s[x + start];
		x++;
		len--;
	}
	newchain[x] = '\0';
	return (newchain);
}
