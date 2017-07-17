# C-TCP_ServerClient
A program that creates a network server on Linux OS and connects clients to the server, allowing communication.


//Runs in linux's terminal with the following commands:

gcc -o linuxServer linuxServer.c

gcc -o linuxClient linuxClient.c

//This creates two c-executables through terminal. Now execute the two programs in terminal:

linuxServer

linuxClient

//To start the server, a port number is the input.

//To connect the client to the server, a hostname of the computer running the server is required as well as the port number.

//By using the fork() method, the server may handle multiple clients at once.
