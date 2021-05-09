#include <iostream>

int main() {
    int L, C, answer;

    std::cin >> L >> C;

    if((L + C) % 2 == 0)
        answer = 1;
    else
        answer = 0;

    std::cout << answer << std::endl;

    return 0;
}