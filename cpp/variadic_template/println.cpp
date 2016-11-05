#include <iostream>

void println(std::ostream& out){
    out << std::endl;
}

template<typename Head, typename... Tail>
void println(std::ostream& out, const Head& head, const Tail& ...tail){
    out << head;
    if( sizeof...(tail) ){
        out << ", ";
        println(out, tail...);
    }
    else{
        out << std::endl;
    }
}

int main(int argc, char *argv[]){
    println(std::cout, 1, 'c', 540, "hello", 3.45);
    return 0;
}
