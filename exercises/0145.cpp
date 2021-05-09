#include <iostream>

int main() {
    int X;

    std::cin >> X;

    if(X > 0)
        std::cout << "positivo" << std::endl;
    else if(X == 0) 
        std::cout << "nulo" << std::endl;
    else
        std::cout << "negativo" << std::endl;

    return 0;
}