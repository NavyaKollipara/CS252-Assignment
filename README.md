## Question-1
Design a program using ordinary pipes in which one process sends a string message to second process, and second process reverses the case of each character in message and sends back to the first process.

### For example : 
If first process sends the message `Hello World`, the second process should return `hELLO wORLD`

## Question-2
Design a file-copying program named filecopy.c using ordinary pipes.
The program will be passed two parameters:
* The name of file to be copied
* The name of destination file

The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe. The child process will read this file from the  pipe and write it to the destination file. 

### For example, if we invoke the program as follows:
          ./filecopy input.txt copy.txt
The file `input.txt` will be written to the pipe. The child process will read the contents of this file and write it to the destination file `copy.txt`.
