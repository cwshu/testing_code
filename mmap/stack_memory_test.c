#include <stdio.h>

#define STOP() \
    getchar(); getchar();

void recursive_f(int num){
    unsigned char buf[1024];
    
    if(num == 0){
        STOP()
        return;
    }
    recursive_f(num-1);
}

int main(int argc, char *argv[]){
    int times;

    printf("input times of function call:\n");
    scanf("%d", &times);
    recursive_f(times);
    return 0;
}
