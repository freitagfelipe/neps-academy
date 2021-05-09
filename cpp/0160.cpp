#include <iostream>

int main() {
    int N, answer = 0;

    std::cin >> N;

    char listOfAnswers[N], userAnswer;

    for(int i = 0; i < N; i++) 
        std::cin >> listOfAnswers[i];

    for(int i = 0; i < N; i++) {
        std::cin >> userAnswer;

        if(userAnswer == listOfAnswers[i])
            answer++;
    }

    std::cout << answer << std::endl;

    return 0;
}