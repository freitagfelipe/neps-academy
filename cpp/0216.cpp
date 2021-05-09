#include <iostream>

int main() {
    int X;

    std::cin >> X;

    for(int i = 1; i <= X; i++)
        if(X % i == 0)
            std::cout << i << " ";

    std::cout << '\n';

    return 0;
}