#include <iostream>

int main() {
    int N, X, answer = 0;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> X;
        answer += X;
    }

    std::cout << answer << std::endl;

    return 0;
}