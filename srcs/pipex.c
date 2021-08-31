#include "pipex.h"

void    child_one(int *end, char **argv, char **envp)
{
    char    *cmd;
    char    **buff;
    char    **path;
    int     file;
    int     i;

    i = -1;
    path = ft_split(envp[0], ':');
    file = open(argv[1], O_RDONLY);
    if (file < 0)
    {
        perror("Open: ");
        exit(0);
    }
    dup2(file, STDIN_FILENO);
    dup2(end[1], STDOUT_FILENO);
    close(end[0]);
    close(file);
    while(path[++i])
    {
        cmd = ft_strjoin(path[i], "/");
        cmd = ft_strjoin(cmd, argv[2]);
        buff = ft_split(cmd, ' ');
        cmd = buff[0];
        execve(cmd, ft_split(argv[2], " "), envp);
        free(cmd);
    }
}

void    child_two(int *end, char **argv, char **envp)
{
    char    *cmd;
    char    **buff;
    char    **path;
    int     file;
    int     i;

    i = -1;
    path = ft_split(envp[0], ':');
    file = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
    if (file < 0)
    {
        perror("Open: ");
        exit(0);
    }
    dup2(file, STDOUT_FILENO);
    dup2(end[0], STDIN_FILENO);
    close(end[1]);
    close(file);
    while(path[++i])
    {
        cmd = ft_strjoin(path[i], "/");
        cmd = ft_strjoin(cmd, argv[3]);
        buff = ft_split(cmd, ' ');
        cmd = buff[0];
        execve(cmd, ft_split(argv[3], " "), envp);
        free(cmd);
    }
}

int		main(int argc, char **argv, char **envp) {
    int end[2];
    int status;
    pid_t child1;
    pid_t child2;

    status = 0;
    if (argc != 5)
    {
        ft_putstr_fd("no valid arguments\n", 2);
        return (0);
    }
    if (pipe(end) == -1)
        return (0);
    child1 = fork();
    if (child1 < 0)
    {
        perror("Fork: ");
        return (0);
    }
    if (child1 == 0)
        child_one(end, argv, envp);
    child2 = fork();
    if (child2 < 0)
    {
        perror("Fork: ");
        return (0);
    }
    if (child2 == 0)
        child_two(end, argv, envp);
    close(end[0]);
    close(end[1]);
    waitpid(-1, &status, 0);
    waitpid(-1, &status, 0);
    return (0);
}
