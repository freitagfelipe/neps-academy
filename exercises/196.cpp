#include <iostream>

int main() {
    int N, Q, X;
    std::string answer;

    std::cin >> N;

    int arrayN[N];

    for(int i = 0; i < N; i++) {
        std::cin >> arrayN[i];
    }

    std::cin >> Q;

    for(int i = 0; i < Q; i++) {
        answer = "";

        std::cin >> X;

        for(int j = 0; j < N; j++)
            if(arrayN[j] == X)
                answer = "Sim";

        if(!(answer == "Sim")) {
            answer = "Nao";
        }

        std::cout << answer << std::endl;
    }

    return 0;
}