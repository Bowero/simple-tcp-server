#include <ctype.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <unistd.h>

/* this tcp port is our default port */
#define DEFAULT_PORT "3490"

/* the maximum length of the queue of pending connections */
#define DEFAULT_BACKLOG 10

/* the maximum size of the incoming buffer */
#define DEFAULT_BUFFERSIZE 256

void error(char *msg)
{
    /* convert the errno to something useful */
    perror(msg);
    exit(1);
}

void usage() {

    // print the help info
    printf("\n"
    "Usage: ./simple-tcp-server --port 3490 --backlog 10\n"
    "\n"
    "   This application is a small program that allows you to run a local TCP server.\n"
    "   The program is easy to extend.\n" 
    "   Using it, is just as easy. Run the script with the options that you want.\n"
    "\n"
    "   NOTE: wrong options will just be ignored by the application.\n"
    "\n"
    "Options:\n"
    "\n"
    "   -p / --port             Which port to use to open the server on \n"
    "                           (default: 3490)\n"
    "\n"
    "   -b / --backlog          How many connections to accept in queue\n"
    "                           (default: 10)\n"
    "\n"
    "   -bs / --buffersize      The size of the buffer of the incoming messages\n"
    "                           (default: 256)\n"
    "\n"
    "   -h / --help             Show this information\n"
    "\n"
    "   -v / --version          Show the current version of simple-tcp-server\n"
    "\n"
    "Report bugs to ik@robinmartijn.nl or resolve them yourself.\n"
    "\n"
    );

    // close the application
    exit(0);
}

void version(char *cv) {
    printf("Current version: %s\n", cv);
    exit(0);
}

/* check if the string is a number */
bool isNumber(char *s) 
{ 
    /* loop through every character until we encounter a null byte */
    for (int i = 0; s[i] != '\0'; i++) 

        /* check if the character is a digit */
        if (!isdigit(s[i])) 

            /* the string can't be a number now */
            return false; 
  
    /* all characters are digits */
    return true; 
} 

void feedback(int portno, int backlog, int buffersize, char *version) {
    printf("\n"
"      _                 _             _                                                \n"
"     (_)               | |           | |                                               \n"
"  ___ _ _ __ ___  _ __ | | ___ ______| |_ ___ _ __ ______ ___  ___ _ ____   _____ _ __ \n"
" / __| | '_ ` _ \\| '_ \\| |/ _ \\______| __/ __| '_ \\______/ __|/ _ \\ '__\\ \\ / / _ \\ '__|\n"
" \\__ \\ | | | | | | |_) | |  __/      | || (__| |_) |     \\__ \\  __/ |   \\ V /  __/ |   \n"
" |___/_|_| |_| |_| .__/|_|\\___|       \\__\\___| .__/      |___/\\___|_|    \\_/ \\___|_|   \n"
"                 | |                         | |                                       \n"
"                 |_|                         |_|                                       \n");
    printf("\nStarting the server\n");
    printf("Version:            %s\n", version);
    printf("\n");
    printf("Port:               %i\n", portno);
    printf("Backlog size:       %i\n", backlog);
    printf("Buffersize:         %i\n", buffersize);
}