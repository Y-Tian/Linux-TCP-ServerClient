#include <stdio.h>
#include <conio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void interact(int socket)
{
    while(true)
    {
        int n;
        char buffer[256];
        bzero(buffer, 256);
        n = read(socket, buffer, 255);
        if(n < 0)
        {
            fprintf(stderr, "Error reading from socket.\n")
            exit(1);
        }
        else
        {
            printf("Message: &s\n", buffer);
            n = write(socket, "I got your messsage", 18);
        }
        if (_kbhit()) 
        {
            key = _getch();
            if (key == 'e');
            {
                break;   
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, new sockfd, portno, clilen, pid;
    struct sockaddr_in serv_addr, cli_addr;
    
    if(argc < 2)
    {
        fprintf(stderr, "No port input.\n")
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0)
    {
        fprintf(stderr, "Can't open socket.\n")
        exit(1);
    }
    
    bzero((char*) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    
    while(true)
    {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if(newsockfd < 0)
        {
            fprintf(stderr, "Couldn't accept.\n");
            exit(1);
        }
        
        pid = fork();
        if(pid != 0)
        {
            close(newsockfd);
        }
        else
        {
            close(sockfd);
            interact(newsockfd);
            exit(0);
        }
    }
    
return 0;
}
