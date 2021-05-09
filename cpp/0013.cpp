#include <iostream>

int main() {
    int A, M;
    char answer = 'N';

    std::cin >> A >> M;

    if(A + M <= 50)
        answer = 'S';

    std::cout << answer << std::endl;

    return 0;
}