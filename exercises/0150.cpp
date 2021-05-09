#include <iostream>

int main() {
    int N, answer;

    std::cin >> answer;

    for(int i = 0; i < 2; i++) {
        std::cin >> N;

        if(N > answer)
            answer = N;
    }

    std::cout << answer << std::endl;

    return 0;
}