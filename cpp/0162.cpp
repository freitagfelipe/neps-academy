#include <iostream>

int main() {
    int D, answer;

    std::cin >> D;

    if(D <= 800)
        answer = 1;
    else if(D <= 1400)
        answer = 2;
    else
        answer = 3;

    std::cout << answer << std::endl;

    return 0;
}