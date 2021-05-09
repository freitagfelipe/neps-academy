#include <iostream>

int main() {
    int P1, C1, P2, C2, answer;
    
    std::cin >> P1 >> C1 >> P2 >> C2;

    P1 *= C1;
    P2 *= C2;

    if(P1 > P2)
        answer = -1;
    else if(P2 > P1)
        answer = 1;
    else
        answer = 0;
    
    std::cout << answer << std::endl;

    return 0;
}