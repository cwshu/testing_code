#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int pid;

    printf("before fork\n");
    pid = fork();
    printf("after fork\n");

    return 0;
}
