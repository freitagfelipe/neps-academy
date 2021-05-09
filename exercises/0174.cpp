#include <iostream>

int fatorial(int N);

int main() {
    int X;

    std::cin >> X;

    std::cout << fatorial(X) << std::endl;

    return 0;
}

int fatorial(int N) {
    if(N == 0)
        return 1;

    return N * fatorial(N - 1);
}