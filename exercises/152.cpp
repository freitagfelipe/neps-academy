#include <iostream>

int main() {
    long int X;

    std::cin >> X;

    for(int i = X + 1; i <= X + 10; i++)
        std::cout << i << " ";

    std::cout << '\n';

    return 0;
}