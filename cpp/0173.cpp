#include <iostream>

int main() {
    int N, X = 0, Y = 1, Z = 0;

    std::cin >> N;

    std::cout << Z << " ";

    Z = 1;

    for(int i = 0; i < N - 1; i++) {
        std::cout << Z << " ";

        Z = Y + X;
        X = Y;
        Y = Z;
    }

    std::cout << "\n";

    return 0;
}