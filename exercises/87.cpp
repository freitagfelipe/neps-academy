#include <iostream>

int main() {
    int P, R;
    char answer;

    std::cin >> P >> R;

    if(P == 0)
        answer = 'C';
    else {
        if(R == 0)
            answer = 'B';
        else {
            answer = 'A';
        }
    }

    std::cout << answer << std::endl;

    return 0;
}