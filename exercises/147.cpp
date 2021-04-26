#include <iostream>

int main() {
    double N1, N2;
    std::string answer;

    std::cin >> N1 >> N2;

    if((N1 * 2 + N2 * 3) / 5 >= 7)
        answer = "Aprovado";
    else if((N1 * 2 + N2 * 3) / 5 < 3)
        answer = "Reprovado";
    else
        answer = "Final";

    std::cout << answer << std::endl;

    return 0;
}