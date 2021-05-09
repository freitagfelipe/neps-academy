#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double X, Y;

    std::cin >> X >> Y;

    std::cout << std::fixed << std::setprecision(4) << pow(X, Y) << std::endl;

    return 0;
}