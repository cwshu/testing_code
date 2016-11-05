#include <iostream>

template<typename T>
void P(T x){
    std::cout << x << ' ';
}

// foo declaration
void foo(char a);

template<typename ... ARGS>
void foo(int a, ARGS ... args);

template<typename ... ARGS>
void foo(char a, ARGS ... args);

// foo instance
void foo(char a){
    P(3);
    P(a);
}

template<typename ... ARGS>
void foo(int a, ARGS ... args){
    foo(args ...);
    P(a);
}

template<typename ... ARGS>
void foo(char a, ARGS ... args){
    P(a);
    foo(args ...);
}

int main(int argc, char *argv[]){
    foo('1', '2', 48, '4', '5');
    return 0;
}
