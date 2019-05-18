# this makefile can be used to easily compile the project.

SRCS = server.c
CFLAGS = -Wall -g -Wimplicit-function-declaration
LIBS = . 
TARGET = server

all: $(SRCS)
	@echo Installing the server...
	gcc $(CFLAGS) $(SRCS) -I $(LIBS)-o $(TARGET)

install: $(SRCS)
	@echo Installing the server...
	gcc $(SRCS) -I $(LIBS)-o $(TARGET)

clean: 
	@echo Removing the executable
	rm $(TARGET)