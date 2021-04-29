#include <iostream>

int main() {
    double A, B;
    std::string answer;

    std::cin >> A >> B;

    if((A + B) / 2 >= 7)
        answer = "Aprovado";
    else if((A + B) / 2 < 4)
        answer = "Reprovado";
    else
        answer = "Recuperacao";

    std::cout << answer << std::endl;

    return 0;
}