#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAXLINE 128

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	
	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n') 
			buf[strlen(buf) - 1] = 0;
		
		if ((pid = fork()) < 0) {
			printf("fork error");
		} else if (pid == 0) {
			execlp(buf, buf, (char *)0);
			printf("Couldn't execute: %s", buf);
			exit(127);
		}
		
		
		if ((pid = waitpid(pid, &status, 0)) < 0) {
			printf("waitpid error");
		}
		printf("%% ");
	}
	exit(0);
} 
