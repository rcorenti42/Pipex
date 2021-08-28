/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 02:39:20 by rcorenti          #+#    #+#             */
/*   Updated: 2019/11/14 22:41:45 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*place;

	place = NULL;
	if (!(place = malloc(size * elements)))
		return (NULL);
	ft_bzero(place, elements * size);
	return (place);
}
