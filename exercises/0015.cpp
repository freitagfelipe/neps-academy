#include <iostream>
#include <cmath>

int main() {
    int C, A;
    double answer;

    std::cin >> C >> A;

    if(C > A)
        answer = 1;
    else
        answer = double(A) / (C - 1);

    std::cout << ceil(answer) << std::endl;

    return 0;
}