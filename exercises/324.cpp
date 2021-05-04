#include <iostream>

int main() {
    int N, L, C, answer = 0;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> L >> C;

        if(L > C)
            answer += C;
    }

    std::cout << answer << std::endl;

    return 0;
}