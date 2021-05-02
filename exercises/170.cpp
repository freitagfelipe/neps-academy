#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int N;
    double X;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> X;
        std::cout << std::fixed << std::setprecision(4) << sqrt(X) << std::endl;
    }

    return 0;
}