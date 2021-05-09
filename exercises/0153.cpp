#include <iostream>

int main() {
    int X, answer = 0;

    while(std::cin >> X && X != 2018)
        answer++;

    std::cout << answer << std::endl;

    return 0;
}