/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:00:02 by rcorenti          #+#    #+#             */
/*   Updated: 2019/11/18 16:06:52 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_letters(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static void		ft_freetab(char **tab, int i)
{
	while (i)
		free(&tab[i--]);
	free(tab);
}

static int		ft_memstr(int x, char c, char **tab, const char *s)
{
	int	i;
	int	z;

	i = 0;
	while (i < x)
	{
		while (*s == c)
			s++;
		s++;
		if (!(tab[i] = malloc(sizeof(char) * ft_letters(--s, c) + 1)))
		{
			ft_freetab(tab, i);
			return (0);
		}
		z = 0;
		while (*s != '\0' && *s != c)
			tab[i][z++] = *s++;
		tab[i][z] = '\0';
		i++;
	}
	return (1);
}

char			**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			x++;
		i++;
	}
	if (!(tab = malloc(sizeof(char *) * (x + 1))))
		return (NULL);
	tab[x] = NULL;
	if (ft_memstr(x, c, tab, s) == 0)
		return (NULL);
	return (tab);
}
