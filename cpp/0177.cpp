#include <iostream>

int main() {
    int numbers[3], answer = 0;

    for(int i = 0; i < 3; i++)
        std::cin >> numbers[i];

    for(int i = 0; i < 3; i++)
        if(numbers[i] % 2 == 0 || (numbers[i] % 5 == 0 && numbers[i] % 2 != 0))
            answer++;

    std::cout << answer << std::endl;

    return 0;
}