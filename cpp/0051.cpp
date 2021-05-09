#include <iostream>

int main() {
    int P, D1, D2, answer;

    std::cin >> P >> D1 >> D2;

    if(P == 0) {
        if((D1 + D2) % 2 == 0)
            answer = 0;
        else
            answer = 1;
    } else {
        if((D1 + D2) % 2 == 0)
            answer = 1;
        else
            answer = 0;
    }

    std::cout << answer << std::endl;

    return 0;
}