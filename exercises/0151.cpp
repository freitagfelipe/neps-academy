#include <iostream>

int main() {
    int numbers[3];

    for(int i = 0; i < 3; i++)
        std::cin >> numbers[i];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(numbers[i] < numbers[j])
                std::swap(numbers[i], numbers[j]);

    for(int i = 0; i < 3; i++)
        std::cout << numbers[i] << std::endl;

    return 0;
}