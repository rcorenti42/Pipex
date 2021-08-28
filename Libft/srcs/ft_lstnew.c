/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 04:20:57 by rcorenti          #+#    #+#             */
/*   Updated: 2021/08/13 04:21:05 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *list;
    list = (t_list *)malloc(sizeof(t_list));
    if (list)
    {
        list->content = content;
        list->next = NULL;
    }
    return (list);
}