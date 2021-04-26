#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int R;

    std::cin >> R;

    std::cout << std::fixed << std::setprecision(2) << 3.1416 * pow(R, 2) << std::endl;

    return 0;
}