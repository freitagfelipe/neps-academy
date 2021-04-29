#include <iostream>

int main() {
    int A, B, C;
    char answer;

    std::cin >> A >> B >> C;

    if(A == B && B == C)
        answer = '*';
    else if(A == B)
        answer = 'C';
    else if(A == C)
        answer = 'B';
    else if(B == C)
        answer = 'A';

    std::cout << answer << std::endl;

    return 0;
}