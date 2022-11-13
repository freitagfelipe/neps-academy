#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;

    std::cin >> N;

    int numbers[N];

    for(int i = 0; i < N; i++)
        std::cin >> numbers[i];

    std::vector<int> numbersVector(numbers, numbers + N);

    std::sort(numbersVector.begin(), numbersVector.end());

    for(std::vector<int>::iterator i = numbersVector.begin(); i != numbersVector.end(); i++)
        std::cout << *i << " ";

    std::cout << '\n';

    return 0;
}