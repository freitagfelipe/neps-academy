#include <iostream>

int main() {
    int N, answer = 0;

    std::cin >> N;

    int numbers[N];

    for(int i = 0; i < N; i++)
        std::cin >> numbers[i];
    
    for(int i = 0; i < N - 2; i++) {
        if(numbers[i] == 1 && numbers[i + 1] == 0 && numbers[i + 2] == 0)
            answer++;
    }

    std::cout << answer << std::endl;

    return 0;
}