#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 

int main ( int argc, char* argv[])

{
    int pipeFd[2];
    char parentBuffer[200];
    char childBuffer[200];

    /* returns error if number of arguments is not three */
    if (argc != 3) 
       {
            /* perror() prints error message to stderr */
            perror("Filecopy: filecopy.exe\n");
            exit(1);
       }


    if( pipe(pipeFd) == -1)
       {
           printf("Error");
           return -1;
       }

    char* sourceFile = argv[1];
    char* targetFile = argv[2];

    int pid = fork();

    if (pid == -1)
        {
            printf("Error");
            return -1;
        }

    // child process
    else if (pid == 0)
        {
            close(pipeFd[1]);

            /* reads n bytes from file associated with open file descriptor into buffer */ 
            ssize_t numBytes_Child = read(pipeFd[0],childBuffer,sizeof(childBuffer));
            close(pipeFd[0]);
            
            /* open() system call opens the path specified by pathname(targetFile) */
            int targetDesc = open(targetFile, O_WRONLY);

            /* writes n bytes (given by numBytes_Child) from buffer to file referred by file descriptor */
            write(targetDesc,childBuffer,numBytes_Child);

        }    
    
    else
        {
            close(pipeFd[0]);

            /* open() system call opens the path specified by pathname(sourceFile) */
            int sourceDesc = open(sourceFile,O_RDONLY);

            /* reads n bytes from file associated with open file descriptor into buffer */ 
            ssize_t numBytes_Parent = read(sourceDesc,parentBuffer,sizeof(parentBuffer));
            
            /* writes n bytes (given by numBytes_Parent) from buffer to file referred by file descriptor */
            write(pipeFd[1],parentBuffer,numBytes_Parent);
            close(pipeFd[1]);

        }
}
