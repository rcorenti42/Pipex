#include <unistd.h>

void	analyse()
{
}

void	parent_process(int f2, int cmd2)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(f2);
}

void	child_process(int f1,int cmd1)
{
	if (dup2() < 0)
		exit();
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int	end[2];
	t_pid parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child_process(f1, cmd1);
	else
		parent_process(f2, cmd2);
}

int		main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | ORDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, argv, envp);
	return (0);
}
