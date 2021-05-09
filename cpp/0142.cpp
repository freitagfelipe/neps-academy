#include <iostream>

int main() {
    int H, M;

    std::cin >> H >> M;

    std::cout << (H * 60) + M << std::endl;

    return 0;
}