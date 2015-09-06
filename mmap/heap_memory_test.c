#include <stdio.h>
#include <stdlib.h>

#define STOP() \
    getchar(); getchar();

int main(int argc, char *argv[]){
    int size, type;

    printf("input malloc size type: [1] 2^size [2] size\n");
    scanf("%d", &type);
    
    if(type == 1)
        printf("input malloc size: (2^size)\n");
    else if(type == 2)
        printf("input malloc size: (size)\n");
    scanf("%d", &size);

    int *a;
    if(type == 1)
        a = (int*)malloc(1<<size);
    else if(type == 2)
        a = (int*)malloc(size);

    STOP();
    return 0;
}
