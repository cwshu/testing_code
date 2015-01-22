#include <iostream>
#include <cstdio>
#include <cerrno>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
using namespace std;

int main(){

    int pid = fork();
    if( pid == 0 ){
        int fd = open("output2", O_WRONLY | O_CREAT | O_APPEND, 0666);
        // int fd = open("output2", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        cout << "[child] sleep" << endl;
        sleep(1);
        cout << "[child] write to file" << endl;
        write(fd, "hello child\n", 12);
    }
    else if( pid > 0 ){
        int fd = open("output2", O_WRONLY | O_CREAT | O_APPEND, 0666);
        // int fd = open("output2", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        cout << "[parent] sleep" << endl;
        sleep(1);
        wait(NULL);
        cout << "[parent] write to file" << endl;
        write(fd, "hello parent\n", 13);
    }
    else{
        perror("fork error");
    }

    return 0;
}
