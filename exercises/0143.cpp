#include <iostream>

int main() {
    int M[6] = {100, 50, 25, 10, 5, 1}, C, answer[7] = {0};

    std::cin >> C;

    for (int i = 0; i < 6; i++) {
        if (C / M[i] > 0) {
            answer[i + 1] = C / M[i];
            C %= M[i];
        }

        if (i == 5)
            for (int i = 1; i < 7; i++)
                answer[0] += answer[i];
    }

    for (int i = 0; i < 7; i++)
        std::cout << answer[i] << std::endl;

    return 0;
}