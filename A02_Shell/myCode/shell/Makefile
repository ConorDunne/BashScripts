CC=gcc
CFLAGS=-g -Wall
HFILES=header.h
OBJ=main.o catchSignal.o commands.o execvpFork.o inputCommand.o path.o time.o 

all: shell

shell: $(OBJ)
	$(CC) $(LIBS) $^ -o $@

%.o: %.c $(HFILES)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o shell
