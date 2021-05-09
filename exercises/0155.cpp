#include <iostream>

int main() {
    int N, answer[3] = {0};

    std::cin >> N;

    for(int i = 0, x; i < N; i++) {
        std::cin >> x;

        if(x % 2 == 0)
            answer[0]++;
        if(x % 3 == 0)
            answer[1]++;
        if(x % 4 == 0)
            answer[2]++;
    }

    for(int i = 0; i < 3; i++)
        std::cout << answer[i] << std::endl;

    return 0;
}