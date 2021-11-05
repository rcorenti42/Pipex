#include "pipex.h"

char    *ft_path(char *cmd, char **env)
{
    char    *path;
    char    *ret;
    char    **tab;
    int     i;

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

void    ft_father(char **argv, char **env, int *pip)
{
    int     fd;
    char    **cmd;

    fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (!fd)
        exit(EXIT_FAILURE);
    cmd = ft_split(argv[3], ' ');
    dup2(pip[0], STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(pip[1]);
    if (!execve(ft_path(cmd[0], env), cmd, env))
        exit(EXIT_FAILURE);
}

void    ft_child(char **argv, char **env, int *pip)
{
    int     fd;
    char    **cmd;

    fd = open(argv[1], O_RDONLY, 0777);
    if (!fd)
        exit(EXIT_FAILURE);
    cmd = ft_split(argv[2], ' ');
    dup2(pip[1], STDOUT_FILENO);
    dup2(fd, STDIN_FILENO);
    close(pip[0]);
    if (!execve(ft_path(cmd[0], env), cmd, env))
        exit(EXIT_FAILURE);
}

int     main(int argc, char **argv, char **env)
{
    int pip[2];
    int pid;

    if (argc != 5)
    {
        ft_putstr_fd("Incorrect number of arguments.", 2);
        return (0);
    }
    if (!pipe(pip))
        exit(EXIT_FAILURE);
    pid = fork();
    if (!pid)
        exit(EXIT_FAILURE);
    if (pid == 0)
        ft_child(argv, env, pip);
    waitpid(pid, NULL, 0);
    ft_father(argv, env, pip);
    close(pip[0]);
    close(pip[1]);
    return (0);
}