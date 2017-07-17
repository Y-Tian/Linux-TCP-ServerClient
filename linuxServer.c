#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void interact(int);


int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, pid;
    struct sockaddr_in serv_addr, cli_addr;
    
    if(argc < 2)
    {
        fprintf(stderr, "No port input.\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0)
    {
        fprintf(stderr, "Can't open socket.\n");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    {
	fprintf(stderr, "Can't bind.\n");
        exit(1);
    }
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1)
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

void interact(int socket)
{
    while(1)
    {
        int n;
        char buffer[256];
        bzero(buffer, 256);
        n = read(socket, buffer, 255);
        if(n < 0)
        {
            fprintf(stderr, "Error reading from socket.\n");
            exit(1);
        }
        else
        {
            printf("Message: %s\n", buffer);
            n = write(socket, "I got your message", 18);
        }
    }
}
