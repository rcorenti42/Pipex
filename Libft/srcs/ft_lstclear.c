/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:10:32 by rcorenti          #+#    #+#             */
/*   Updated: 2021/08/13 05:10:35 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *tmp;

    if (lst)
    {
        while (*lst != NULL)
        {
            tmp = (*lst)->next;
            ft_lstdelone(*lst, del);
            *lst = tmp;
        }
        *lst = NULL;
    }
}