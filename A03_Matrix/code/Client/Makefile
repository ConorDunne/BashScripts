CC=gcc
CFLAGS=-g -Wall
HFILES=header.h
OBJ=main.o printMatrix.o connection.o multiplyVectors.o

all: client

client: $(OBJ)
	$(CC) $(LIBS) $^ -o $@

%.o: %.c $(HFILES)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o client
