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
    char* addr;
    struct stat sb;

    fd = shm_open(argv[1], O_RDONLY, 0);

    fstat(fd, &sb);
    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    close(fd); /* ’fd’ is no longer needed */

    write(STDOUT_FILENO, addr, sb.st_size);
    printf("\n");
    return 0;
}
