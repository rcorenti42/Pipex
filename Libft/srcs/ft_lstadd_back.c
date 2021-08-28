/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 04:50:45 by rcorenti          #+#    #+#             */
/*   Updated: 2021/08/13 04:50:47 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (lst)
    {
        if (*lst)
        {
            tmp = ft_lstlast(*lst);
            tmp->next = new;
        }
        else
            *lst = new;
    }
}