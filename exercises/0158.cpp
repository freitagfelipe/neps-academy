#include <iostream>

int fatorial(int n1);

int main() {
    int N;

    std::cin >> N;

    std::cout << fatorial(N) << std::endl;

    return 0;
}

int fatorial(int n1) {
    if(n1 == 0) {
        return 1;
    }

    return n1 * fatorial(n1 - 1);
}