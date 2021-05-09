#include <iostream>

int main() {
    int N1, N2;

    std::cin >> N1 >> N2;

    if(N1 > N2)
        std::swap(N1, N2);

    for(int i = N1; i <= N2; i++)
        std::cout << i << " ";

    std::cout << '\n';

    return 0;
}