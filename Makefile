# this makefile can be used to easily compile the project.

SRCS = server.c
CFLAGS = -Wall -g -Wimplicit-function-declaration
LIBS = . 
TARGET = simple-tcp-server
DEST = /usr/local/bin/stcps

all: $(SRCS)
	@echo Installing the server...
	gcc $(CFLAGS) $(SRCS) -I $(LIBS)-o $(TARGET)
	cp $(TARGET) $(DEST)

install: $(SRCS)
	@echo Installing the server...
	gcc $(SRCS) -I $(LIBS)-o $(TARGET)
	cp $(TARGET) $(DEST)

clean: 
	@echo Removing the executable
	rm $(TARGET)
	rm /usr/local/bin/stcps
