#ifdef HAVE_CONFIG_H
# include<config.h>
#endif

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    char *arg[]={"ls","-a",NULL};

    if(fork()==0)
    {
        // in child
	printf(" I am execl\n");
	if (execl("/bin/ls","ls","-a",NULL)==-1);
	{ 
	   perror("execl error");
	   exit(1);
	 }
     }

    if (fork()==0)
    {
        printf("i am execv\n");
	if(execv("/bin/ls",arg)<0)
	{
	   perror("execv error");
	   exit(1);
	   }
    }

	
    if (fork()==0)
    {
        printf("i am execlp\n");
	if(execlp("ls","ls","-a",NULL)<0)
	{
	   perror("execlp error");
	   exit(1);
	   }
    }
    
    if (fork()==0)
    {
        printf("i am execvp\n");
	if(execvp("ls",arg)<0)
	{
	   perror("execvp error");
	   exit(1);
	   }
    }


    if (fork()==0)
    {
        printf("i am execle\n");
	if(execle("/bin/ls","ls","-a",NULL,NULL)==-1)
	{
	   perror("execle error");
	   exit(1);
	   }
    }

    
    if (fork()==0)
    {
        printf("i am execve\n");
	if(execve("/bin/ls",arg,NULL)==0)
	{
	   perror("execve error");
	   exit(1);
	   }
    }

    return EXIT_SUCCESS;

}
