#include "pipex.h"
#include <stdio.h>
#include <sys/wait.h>
extern char **environ;
int main(int ac, char **av) {
	pid_t pid;
	char	*argv[3];

	argv[0] = "grep";
	argv[1] = av[1];
	argv[2] = NULL;
	// pid = fork();
	if (pid < 0)
		perror(strerror(errno));
	execve("/usr/bin/grep", argv, environ);
}