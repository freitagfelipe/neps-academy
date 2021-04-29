#include <iostream>

int main() {
    int numberOfFigures, userStickers, answer = 0;

    std::cin >> numberOfFigures >> userStickers;

    int list[userStickers] = {0};

    for(int i = 0; i < userStickers; i++) {
        int test = 1;

        std::cin >> list[i];
    
        for(int j = 0; j < i; j++)
            if(list[i] == list[j])
                test = 0;

        if(test == 1)
            answer++;
    }

    std::cout << numberOfFigures - answer << std::endl;

    return 0;
}