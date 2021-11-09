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

    if (argc != 3) {
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

    else if (pid == 0)
        {
            close(pipeFd[1]);
            ssize_t numBytes_Child = read(pipeFd[0],childBuffer,sizeof(childBuffer));
            close(pipeFd[0]);

            int targetDesc = open(targetFile, O_WRONLY);
            write(targetDesc,childBuffer,numBytes_Child);

        }    
    
    else
        {
            close(pipeFd[0]);
            int sourceDesc = open(sourceFile,O_RDONLY);
            ssize_t numBytes_Parent = read(sourceDesc,parentBuffer,sizeof(parentBuffer));
            write(pipeFd[1],parentBuffer,numBytes_Parent);
            close(pipeFd[1]);

        }
}
