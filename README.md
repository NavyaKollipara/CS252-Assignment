# CS252 (Minors) - Operating Systems Assignment
This assignment contains the solutions to the the following problems in Operating System Concepts, 10th Edition by Abraham Silberschatz, Greg Gagne, Peter B. Galvin:

Chapter 3, Exercise 3.26 (Question 1)

Chapter 3, Exercise 3.27 (Question 2)

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

## References
[Question-1](https://www.youtube.com/watch?v=8Q9CPWuRC6o)

[Question-2](https://quizlet.com/explanations/questions/design-a-file-copying-program-named-filecopy-using-ordinary-pipes-5c666834-900f-40e4-9229-79276f3dc97b)
