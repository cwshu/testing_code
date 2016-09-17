all: mmap_write init

mmap_write: mmap_write.c
	clang mmap_write.c -o mmap_write -lpthread -lrt

init:
	cp input.origin input
	rm -f output

clean:
	rm -rf mmap_write input output
