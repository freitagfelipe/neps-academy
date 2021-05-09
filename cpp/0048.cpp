#include <iostream>

int main() {
    int N, accesses = 0, answer = 0;

    std::cin >> N;

    do {
        int X;

        answer++;

        std::cin >> X;

        accesses += X;

    } while(accesses < 1000000);

    std::cout << answer << std::endl;

    return 0;
}