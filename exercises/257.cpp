#include <iostream>

int main() {
    int N, answer, x = 0, y = 1;

    std::cin >> N;

    if(N == 0 || N == 1)
        answer = 1;
    else
        for(int i = 0; i < N; i++) {
            answer = x + y;
            x = y;
            y = answer;
        }

    std::cout << answer << std::endl;

    return 0;
}