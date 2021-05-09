#include <iostream>

int main() {
    long long int N;
    char answer = 'S';

    std::cin >> N;

    if(N == 1)
        answer = 'N';
    else
        for(int i = 2; i < N; i++)
            if(N % i == 0) {
                answer = 'N';
                break;
            }

    std::cout << answer << std::endl;

    return 0;
}