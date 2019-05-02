CC=gcc
CFLAGS=-g -Wall
HFILES=header.h
OBJ=main.o InitMatrix.o printMatrix.o connection.o  

all: server

server: $(OBJ)
	$(CC) $(LIBS) $^ -o $@

%.o: %.c $(HFILES)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o server
