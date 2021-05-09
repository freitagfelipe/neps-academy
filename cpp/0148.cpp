#include <iostream>

int main() {
    int B, C;

    std::cin >> B >> C;

    if((B + C) % 2 == 0)
        std::cout << "Bino" << std::endl;
    else
        std::cout << "Cino" << std::endl;

    return 0;
}