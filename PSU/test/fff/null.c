/*
** EPITECH PROJECT, 2020
** test [WSL: Ubuntu]
** File description:
** null.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
	{

	int p[2];
	int pid, pid_ret, status;
	
	pipe(p);
	
	printf("Pipe ouvert\n\t- Lecture :\t%d\n\t- Ecriture :\t%d\n", p[0], p[1]);
	
	
	switch( (pid = fork()) )
		{
		case 0: // FILS

			close(STDOUT_FILENO);
			dup(p[1]); //Le premier descripteur libre (stdout) pointe maintenant vers p[1] (écriture dans tube anonyme)
			close(p[1]); // Desormais inutile

			execlp("ls", "ls", "-l", NULL);
			
			break;
		default: // PERE

			printf("Le PERE attend la fin du fils...\n");
			pid_ret = waitpid(pid, &status, 0);
			printf(" ok...\n");
			
			close(STDIN_FILENO);
			dup(p[0]); // Le premier descripteur libre (stdin) pointe maintenant vers p[0] (lecture depuis tube anonyme)
			close(p[0]);
			printf("Execution...\n");
			execlp("ls", "ls", "-a", NULL);
			
		}

	}