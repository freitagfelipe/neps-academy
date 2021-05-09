#include <iostream>

int main() {
    int N, candies[3], answer = 0;

    std::cin >> N;

    for(int i = 0; i < 3; i++)
        std::cin >> candies[i];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(candies[i] < candies[j])
                std::swap(candies[i], candies[j]);

    for(int i = 0, x = 0; i < 3; i++) {
        x += candies[i];
        
        if(x > N) {
            std::cout << answer << std::endl;
            break;
        } else if(i == 2) {
            answer++;
            std::cout << answer << std::endl;
        } else 
            answer++;
    }

    return 0;
}