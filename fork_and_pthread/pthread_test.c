#include <stdio.h>
#include <pthread.h>

void thread_func(){
    printf("thread\n");
}

int main(int argc, char *argv[]){
    pthread_t thread1;

    printf("before pthread_create\n");
    pthread_create(&thread1, NULL, &thread_func, NULL);
    printf("before pthread_create\n");

    pthread_join(thread1, NULL);

    return 0;
}
