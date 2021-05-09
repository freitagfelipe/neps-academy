#include <iostream>

int main() {
    int N, X, answer[2] = {0};

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> X;

        if(X > answer[1])
            answer[1] = X;
        if(X < answer[0] || i == 0)
            answer[0] = X;
    }

    std::cout << answer[1] << "\n" << answer[0] << std::endl;

    return 0;
}