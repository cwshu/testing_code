CC = gcc
CFLAGS = -std=c99

all: process_in_memory libpim.so.1

process_in_memory: process_in_memory.o libpim.so.1.0.0
	$(CC) $(CFLAGS) $^ -o $@

libpim.so.1: libpim.so.1.0.0
	ln -s $< $@

libpim.so.1.0.0: process_in_memory_lib.o
	$(CC) -shared -Wl,-soname,libpim.so.1 -o $@ $<

process_in_memory_lib.o: process_in_memory_lib.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.so.* process_in_memory

