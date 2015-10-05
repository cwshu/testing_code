CC = gcc
CFLAGS = -std=c99 -D_GNU_SOURCE
LD_FLAGS = -lrt

all: pshm_create_simple pshm_write pshm_read

pshm_create_simple: pshm_create_simple.o
	$(CC) $(CFLAGS) $(LD_FLAGS) -o $@ $^

pshm_write: pshm_write.o
	$(CC) $(CFLAGS) $(LD_FLAGS) -o $@ $^

pshm_read: pshm_read.o
	$(CC) $(CFLAGS) $(LD_FLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f *.o pshm_create_simple pshm_write pshm_read
