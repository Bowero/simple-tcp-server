/*
    main.c      a minimal socket server written in c
                because c is fucking awesome

    author      bowero (robin martijn)
*/

#include <server.h>

/* the current version of the software */
#define CURRENT_VERSION "0.1.3"

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, addrlen, backlog;
    char buffer[256];
    struct sockaddr_in serv_addr;
    int n;

    /* this port can be changed in server.h, but you should of course pass a port with --port */
    portno = atoi(DEFAULT_PORT);

    backlog = DEFAULT_BACKLOG;

    /* handle the arguments */
    for (int i = 0; i < argc; i++) {

        /* the user wants to use another port than the default one */
        if (!strcmp(argv[i], "-p") || !strcmp(argv[i], "--port"))

            /* only use the passed argument if it proves to be a number */
            if (isNumber(argv[i+1]))
                portno = atoi(argv[i+1]);

        /* the user wants another backlog size */
        if (!strcmp(argv[i], "-b") || !strcmp(argv[i], "--backlog"))

            /* only use the passed argument if it proves to be a number */
            if (isNumber(argv[i+1]))
                backlog = atoi(argv[i+1]);

        /* the user wants information about the application */
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) 

            /* show usage information */
            usage();

        if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version")) 

            /* show current version */
            version(CURRENT_VERSION);
    }

    /* give the user feedback about the server */
    feedback(portno, backlog);

    /* upon succesfully creating the socket, socket() returns a non-negative number */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* fill in the struct serv_addr */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* creating the socket did not assign an address: that's what we have bind() for */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    /* this marks the socket as passive, so we can receive things on it */
    if (listen(sockfd, backlog) < 0)

        /* this doesn't even happen when the backlog is < 0, 
        so i would love to hear from you if you have this error but better safe than sorry */
        error("ERROR on listening");
        
    /* keep receiving things from clients */    
    while (1) {

        /* clear the buffer */
        bzero(buffer, 256);

        /* the size of the struct */
        addrlen = sizeof(serv_addr);

        /* note: accept blocks the program until it gets a connection
        can be disabled with the flag SOCK_NONBLOCK */
        newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &addrlen);

        /* return value should be 0 once again */
        if (newsockfd < 0) 
            error("ERROR on accept");

        /* the maximum amount of received bytes is 255. to change this,
        you also have to change the buffer size.
        
        TODO: make an argument to do this */
        n = read(newsockfd,buffer,255);

        /* last error handling: you get the idea
        returned value should be 0 */
        if (n < 0) error("ERROR reading from socket");
        printf("Message from client: %s",buffer);

        /* please note that the end of line character is only 1 byte */
        n = write(newsockfd,"I got your message.\n",20);
        if (n < 0) error("ERROR writing to socket");
    }

    /* the end of the program */
    return 0; 
}