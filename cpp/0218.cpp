#include <iostream>
#include <iomanip>

int main() {
    char operation;
    double N1, N2, answer;

    std::cin >> operation >> N1 >> N2;

    switch (operation) {
        case 'M':
            answer = N1 * N2;
            break;
        case 'D':
            answer = N1 / N2;
            break;
    }

    std::cout << std::fixed << std::setprecision(2) << answer << std::endl;

    return 0;
}