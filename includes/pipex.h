#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>

void	child_one(int *end, char **argv, char **envp);
void	child_two(int *end, char **argv, char **envp);

#endif