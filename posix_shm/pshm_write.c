#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd;
    size_t len; /* Sizeof shared memory object */
    char* addr;

    fd = shm_open(argv[1], O_RDWR, 0);
    len = strlen(argv[2]);
    ftruncate(fd, len);
    printf("Resized to %ld bytes\n", (long)len);
    addr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd); /* ’fd’ is no longer needed */
    printf("copying %ld bytes\n", (long)len);
    memcpy(addr, argv[2], len);
    
    return 0;
}
