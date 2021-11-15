/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 03:05:18 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/15 03:05:21 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

char	*ft_path(char *cmd, char **env);
void	ft_father(char **argv, char **env, int *pip);
void	ft_child(char **argv, char **env, int *pip);
void	ft_error(void);

#endif
