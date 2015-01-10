#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void perror_and_exit(const char* msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

/* start_multiprocess_server sub functions */
void sigchid_waitfor_child(int sig){ 
    int status;
    pid_t child;
    printf("recieve signal SIGCHLD\n");
    /* waiting for child process, to prevent child becoming zombie process.
     * use SA_NOCLDWAIT instead of it.
     * while( (child = waitpid(-1, &status, WNOHANG)) > 0 );
     */
}

int main(int argc, char *argv[]){
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigchid_waitfor_child;
    /* signal interrupt system call and library call. (restart call after signal handler) */
    sa.sa_flags |= SA_RESTART; 
    sa.sa_flags |= SA_NOCLDWAIT; 

    if( sigaction(SIGCHLD, &sa, NULL) == -1 ){
        perror_and_exit("sigaction error");
        exit(EXIT_FAILURE);
    }
    
    while(1){
        int child_pid = fork();
        if( child_pid == 0 ){
            printf("I'm child %d\n", getpid());
            exit(EXIT_SUCCESS);
        }
        else if( child_pid > 0 ){
            char tmp[129];
            tmp[0] = getchar();
            /* signal interrupt system call and library call (so call return -1 and errno == EINTR).
             * use SA_RESTART instead of it.
            while( 1 ){
                tmp[0] = getchar();
                if( tmp[0] == -1 && errno == EINTR ) continue;
                break;
            }
            */
            printf("getchar: %d\n", tmp[0]);
        }
        else {
            perror("fork error");
        }
    }

    return 0;
}

