CC = gcc
CFLAGS = -Wall -g

all: shell

shell: main.o input.o commands.o execute.o
	$(CC) $(CFLAGS) -o shell main.o input.o commands.o execute.o

main.o: src/main.c src/shell.h
	$(CC) $(CFLAGS) -c src/main.c

input.o: src/input.c src/shell.h
	$(CC) $(CFLAGS) -c src/input.c

commands.o: src/commands.c src/shell.h
	$(CC) $(CFLAGS) -c src/commands.c

execute.o: src/execute.c src/shell.h
	$(CC) $(CFLAGS) -c src/execute.c


	
clean:
	make && rm -f *.o shell
