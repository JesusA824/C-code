/* In this code a single parent source is created.
The user can specify the desired number of hello worlds
to be printed out.
Each child has its own unique pid where the parent has 
the same one because it is the same one parent process. 
*/

#include <stdio.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <stdlib.h>

int main()

{
  int numfork; //variable to hold user input
  printf("Enter the amount of Hello Worlds or children to be executed: ");
  scanf("%d",&numfork); //accepts user input from keyboard
  
  int i, j;

  for(i = 1; i <= numfork; i++) //loop to run n number of times

  {

      j = fork();

      if(j == 0) //if fork function gives output of 0 then a child is created

      {

	  printf("Hello World: from child %d ",i);//prints out Hello world

          printf("%s %d", "My ppid is [parent one process] ", getppid());

          printf("%s %d.\n", " and my child pid is ", getpid());
	  exit(0);
          sleep(2);

      }

      else
        wait(&j);

  }

  return (0);

}
