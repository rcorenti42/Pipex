/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:45:32 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/15 01:21:10 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*ft_path(char *cmd, char **env)
{
	char	*path;
	char	*ret;
	char	**tab;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	tab = ft_split(env[i] + 5, ':');
	i = 0;
	while (tab[i])
	{
		path = ft_strjoin(tab[i], "/");
		ret = ft_strjoin(path, cmd);
		free(path);
		if (access(ret, F_OK) == 0)
			return (ret);
		i++;
	}
	return (0);
}

void	ft_father(char **argv, char **env, int *pip)
{
	int		fd;
	char	**cmd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		ft_error();
	cmd = ft_split(argv[3], ' ');
	dup2(pip[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pip[1]);
	if (!execve(ft_path(cmd[0], env), cmd, env))
		ft_error();
}

void	ft_child(char **argv, char **env, int *pip)
{
	int		fd;
	char	**cmd;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_error();
	cmd = ft_split(argv[2], ' ');
	dup2(pip[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pip[0]);
	if (!execve(ft_path(cmd[0], env), cmd, env))
		ft_error();
}

int	main(int argc, char **argv, char **env)
{
	int	pip[2];
	int	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number of arguments.\n", 2);
		return (0);
	}
	if (pipe(pip) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
		ft_child(argv, env, pip);
	waitpid(pid, NULL, 0);
	ft_father(argv, env, pip);
	close(pip[0]);
	close(pip[1]);
	return (0);
}
