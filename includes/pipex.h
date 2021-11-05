#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

char    *ft_path(char *cmd, char **env);
void    ft_father(char **argv, char **env, int *pip);
void    ft_child(char **argv, char **env, int *pip);

#endif