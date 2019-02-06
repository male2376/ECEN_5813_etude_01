CC=gcc
CFLAGS=-Wall -Werror

all : clean_all run

run : main.o functions.o
	$(CC) -o RUN main.o functions.o $(CFLAGS)

main.o :
	$(CC) -c main.c $(CFLAGS)

functions.o :
	$(CC) -c functions.c $(CFLAGS)

clean :
	rm -fr RUN
	
clean_all :
	rm -fr RUN
	rm -fr *.o