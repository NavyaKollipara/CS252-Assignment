#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>


int main()
{
    int pipe1[2]; //child to parent
    int pipe2[2]; //parent to child

    if( pipe(pipe1) == -1) 
        {
          return -1;
        }

    if( pipe(pipe2) == -1) 
        {
          return -1;
        }

    int pid = fork();

    if(pid == -1) 
        {
          return -1;
        }
    //child process created
    if(pid == 0)
        {
           /* closing writing end of first pipe and reading end of second pipe */
           close(pipe1[1]);
           close(pipe2[0]);
      
           char Message_Received[100];
         
           /* reversing case of each character in the message received */
           if(read(pipe1[0],Message_Received,sizeof(Message_Received))== -1)
              {
                  return -1;
              }
        
           for(int i=0;i<strlen(Message_Received);i++)
              {
                  if(isupper(Message_Received[i])) 
                     {
                         Message_Received[i] = tolower(Message_Received[i]);
                     }
                 else if (islower(Message_Received[i]))   
                     { 
                         Message_Received[i] = toupper(Message_Received[i]);
                     }
              }
           /* writing back to parent process after reversing case of character */
           if( write(pipe2[1],Message_Received,sizeof(Message_Received))== -1) 
              { 
                   return -1;
              }

           close(pipe1[0]);
           close(pipe2[1]);

       }

    //parent process
    else
       {
           /* closing reading end of first pipe and writing end of second pipe */
           close(pipe1[0]);
           close(pipe2[1]);

           char Message_Sent[100];
           printf("Enter the Message\n");
           scanf("%[^\n]s",Message_Sent);

           /* writing message to child process */
           if(write(pipe1[1],Message_Sent,sizeof(Message_Sent))== -1) 
               {
                   return -1;
               }
           printf("Message Written to Process_2\n");

           /* reading the output message written by child process*/
           if(read(pipe2[0],Message_Sent,sizeof(Message_Sent))== -1) 
              {
                   return -1;
              }
           printf("Message Received back is %s\n",Message_Sent);

           close(pipe1[1]);
           close(pipe2[0]);
       }


     return 0;

}
