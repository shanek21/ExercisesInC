CC = gcc
CFLAGS = -g -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIBS = -lglib-2.0  

word_count: word_count.c
	$(CC) -o $@.o $^ $(CFLAGS) $(LIBS)

mem_errors: mem_errors.c
	$(CC) -o $@.o $^ -g -O0

list_errors: list_errors.c
	$(CC) -o $@.o $^ -g -O0
